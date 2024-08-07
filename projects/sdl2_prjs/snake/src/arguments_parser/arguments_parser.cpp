#include <vector>

#include "src/config/constants.hpp"
#include "src/tools/logger/logger.hpp"
#include "src/tools/utils/utils.hpp"
#include "arguments_parser.hpp"

namespace {
    bool is_full_screen = false;
    unsigned int grid_width = kGridWidth;
    unsigned int grid_height = kGridHeight;
    int snake_initial_body_size = kSnakeInitialBodySize;
    int snake_body_size_to_increase = kSnakeBodySizeToIncrease;
    float snake_initial_speed = kSnakeInitialSpeed;
}

bool app_options::parse(int argc, char *argv[]) {
    if (argc < 2)
        return false;

    const std::vector<std::string_view> args(argv + 1, argv + argc);
    std::string_view arg;

    int i = -1;
    while (i < argc - 1) {
        arg = args[++i];
        if (arg == "-h" || arg == "--help") {
            log("%s", kAppCLIArgumentsUsage.c_str());
            return true;
        }
        if (arg == "-g" || arg == "--cells-width-qty") {
            checkHasArgumentLeft(argc, i);
            arg = args[++i];
            unsigned int tp_val;
            if (!stringViewToNum(arg, tp_val))
                throw std::runtime_error("app: -g/--cells-width-qty parameter value wrong!");
            if (tp_val < kGridWidthMin || tp_val > kGridWidthMax)
                throw std::runtime_error("app: -g/--cells-width-qty parameter value must be between "
                                         + std::to_string(kGridWidthMin) + " and "
                                         + std::to_string(kGridWidthMax) + " !");
            grid_width = tp_val;
            grid_height = grid_width * kGridRatio;
            continue;
        }
        if (arg == "-b" || arg == "--body-pieces") {
            checkHasArgumentLeft(argc, i);
            arg = args[++i];
            int tp_val;
            if (!stringViewToNum(arg, tp_val))
                throw std::runtime_error("app: -b/--body-pieces parameter value wrong!");
            if (tp_val < kSnakeInitialBodySizeMin || tp_val > kSnakeInitialBodySizeMax)
                throw std::runtime_error("app: -b/--body-pieces parameter value must be between "
                                         + std::to_string(kSnakeInitialBodySizeMin) + " and "
                                         + std::to_string(kSnakeInitialBodySizeMax) + " !");
            snake_initial_body_size = tp_val;
            continue;
        }
        if (arg == "-r" || arg == "--body-size-to-increase") {
            checkHasArgumentLeft(argc, i);
            arg = args[++i];
            int tp_val;
            if (!stringViewToNum(arg, tp_val))
                throw std::runtime_error("app: -r/--body-size-to-increase parameter value wrong!");
            if (tp_val < kSnakeBodySizeToIncreaseMin || tp_val > kSnakeBodySizeToIncreaseMax)
                throw std::runtime_error("app: -r/--body-size-to-increase parameter value must be between "
                                         + std::to_string(kSnakeBodySizeToIncreaseMin) + " and "
                                         + std::to_string(kSnakeBodySizeToIncreaseMax) + " !");
            snake_body_size_to_increase = tp_val;
            continue;
        }
        if (arg == "-s" || arg == "--snake-speed") {
            checkHasArgumentLeft(argc, i);
            arg = args[++i];
            float tp_val;
            if (!stringViewToNum(arg, tp_val))
                throw std::runtime_error("app: -s/--snake-speed parameter value wrong!");
            if (tp_val < kSnakeInitialSpeedMin || tp_val > kSnakeInitialSpeedMax)
                throw std::runtime_error("app: -s/--snake-speed parameter value must be between "
                                         + std::to_string(kSnakeInitialSpeedMin) + " and "
                                         + std::to_string(kSnakeInitialSpeedMax) + " !");
            snake_initial_speed = tp_val;
            continue;
        } else if (!arg.empty()) {
            log("%s", kAppCLIArgumentsUsage.c_str());
            return true;
        }
    }
    return false;
}

void app_options::checkHasArgumentLeft(int argc, int i) {
    if (i > argc - 3)
        throw std::runtime_error("app: parameter value missing!");
}

bool app_options::isFullScreen() {
    return is_full_screen;
}

unsigned int app_options::gridWidth() {
    return grid_width;
}

unsigned int app_options::gridHeight() {
    return grid_height;
}

int app_options::snakeInitialBodySize() {
    return snake_initial_body_size;
}

int app_options::snakeBodySizeToIncrease() {
    return snake_body_size_to_increase;
}

float app_options::snakeInitialSpeed() {
    return snake_initial_speed;
}
