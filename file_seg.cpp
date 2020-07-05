#include <cstring>
#include <fstream>
#include <string>
#include "file_seg.h"

using std::ios;
using std::string;

typedef unsigned int uint;

void segment_file(std::string input_file, unsigned int limit, char limit_type)
{
    if (limit_type == 'b')
        segment_file_by_bytes(input_file, limit);
    else if (limit_type == 'l')
        segment_file_by_bytes(input_file, limit);
    else
        return;
}

void segment_file_by_bytes(string input_file, uint limit)
{
    std::ifstream ifs(input_file, ios::binary);
    std::ofstream ofs;
    char name[255];
    uint xt = input_file.rfind(".txt");

    for (int i = 0; ifs.good() == true; i++)
    {
        sprintf(name, "_%03d.txt", i);

        string output_file = input_file.substr(0, xt);
        output_file.append(name);

        ofs.open(output_file, ios::binary);

        for (uint j = 0; j < limit; j++)
        {
            char buffer = ifs.get();

            if (ifs.eof())
                break;

            ofs << buffer;
        }
        ofs.close();
    }
    ifs.close();
}

void segment_file_by_lines(string input_file, uint limit)
{
    std::ifstream ifs(input_file);
    std::ofstream ofs;
    char name[255];
    uint xt = input_file.rfind(".txt");

    for (int i = 0; ifs.good() == true; i++)
    {
        sprintf(name, "_%03d.txt", i);

        string output_file = input_file.substr(0, xt);
        output_file.append(name);

        ofs.open(output_file, ios::out);

        for (uint j = 0; j < limit; j++)
        {
            string buffer;
            getline(ifs, buffer);
            ofs << buffer;

            if (ifs.eof())
                break;
        }
        ofs.close();
    }
    ifs.close();
}
