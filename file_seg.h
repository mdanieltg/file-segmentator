#ifndef FILE_SEG_H
#define FILE_SEG_H

#include <string>

void segment_file(std::string input_file, unsigned int limit, char limit_type);
void segment_file_by_bytes(std::string input_file, unsigned int limit);
void segment_file_by_lines(std::string input_file, unsigned int limit);

#endif // FILE_SEG_H
