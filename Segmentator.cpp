#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char* argv[])
{
    int i;
    char name[10];
    string outputFile, line, filename;
    ifstream sReader;
    ofstream sWriter;

    // Getting file to read
    if (argc > 1)
        outputFile.assign(argv[1]);
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

            for (int j = 0; j < 90000; j++)
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
