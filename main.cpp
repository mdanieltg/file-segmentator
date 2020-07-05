/*
 * Sintaxis:
 *   Modo interactivo:
 *     segment.exe
 *   Línea de comandos:
 *     segment.exe input_file -b bytes_long
 *     segment.exe input_file -l lines_long
 */

#include <iostream>
#include <string>
#include "file_seg.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char** argv)
{
    string input_file, output_file;
    unsigned int limit;
    char limit_type;

    try
    {
        if (argc == 1)
        {
            // Modo interactivo
            cout << "Ruta completa del archivo a segmentar:" << endl;
            std::getline(cin, input_file);

            cout << "Límite en bytes o en líneas: ";
            cin >> limit;

            if (limit <= 0)
//throwhere
                throw 2;

            limit_type = 0;
            do
            {
                cout << "Tipo de límite (b para bytes o l para líneas): ";
                cin >> limit_type;
            }
            while (limit_type != 'b' && limit_type != 'l');
        }
        else if (argc == 4)
        {
            string type(argv[2]);
            if (type.length() == 2 && type[1] == 'b')
                limit_type = 'b';
            else if (type.length() == 2 && type[1] == 'l')
                limit_type = 'l';
            else
//throwhere
                throw 3;

            input_file.assign(argv[1]);

            try
            {
                string buffer(argv[3]);
                limit = std::stoi(buffer);
            }
//throwhere
            catch (std::invalid_argument) { throw 5; }
            catch (std::out_of_range) { throw 6; }

            if (limit <= 0)
//throwhere
                throw 2;
        }
        else
//throwhere
            throw 1;

        segment_file(input_file, limit, limit_type);

        return 0;
    }
    catch (int e)
    {
        if (e == 1)
        {
            // Sintaxis errónea
            cout << "Sintaxis errónea." << endl;
            cout << "Modo interactivo:" << endl;
            cout << "  segment.exe" << endl;
            cout << "Línea de comandos:" << endl;
            cout << "  segment.exe <archivo> -b bytes_límite" << endl;
            cout << "  segment.exe <archivo> -l líneas_límite" << endl;
        }
        else if (e == 2)
            cout << "Debe ingresar un valor numérico mayor a cero (0) como limitador" << endl;

        else if (e == 3)
            cout << "No hay -l o -b" << endl;

        else if (e == 5 || e == 6)
            cout << "Error al leer el parámetro límite" << endl;

        else
            cout << e << endl;
    }

    return 1;
}
