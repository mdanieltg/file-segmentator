#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/*
 * Syntax
 *   Segmentator input_file
 *   Segmentator input_file lines_long_per_file
 *
 */
int main(int argc, const char* argv[])
{
    int i, linesLong = 90000;
    char name[10];
    string outputFile, line, filename;
    ifstream sReader;
    ofstream sWriter;

    // Getting file to read
    if (argc == 1)
        outputFile.assign(argv[1]);
    else if (argc == 2)
    {
        outputFile.assign(argv[1]);
        linesLong = (int)argv[2];
    }
    else
    {
        cout << "Ruta del archivo a segmentar: ";
        getline(cin, outputFile);
    }

    try
    {
        sReader.open(outputFile.c_str(), ios::in);

        i = 0;
        while (!sReader.eof())
        {
            sprintf(name, "_%02d.txt", i);

            filename.assign(outputFile);
            filename = filename.replace(filename.find(".txt"), string::npos, name);

            sWriter.open(filename.c_str(), ios::out);

            for (int j = 0; j < linesLong; j++)
            {
                getline(sReader, line);
                sWriter << line << endl;

                if (sReader.eof())
                    break;
            }
            sWriter.close();

            i++;
        }
        sReader.close();
    }
    catch (exception e)
    {
        cout << e.what() << endl;
    }
}
