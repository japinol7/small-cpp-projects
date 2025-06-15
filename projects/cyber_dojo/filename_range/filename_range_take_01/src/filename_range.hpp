#ifndef FILENAME_RANGE_HPP
#define FILENAME_RANGE_HPP

#include <string>
#include <array>
#include <optional>

/**
 * Calculates the range of characters in a filename that should be selected
 * when renaming the file, excluding directory paths, extensions, and special
 * test-related words.
 *
 * @param filename The filename to analyze
 * @return An optional array containing the start and end indices [start, end],
 *         or std::nullopt for empty input
 */
std::optional<std::array<int, 2>> filename_range(const std::string& filename);

#endif // FILENAME_RANGE_HPP
