//
// Created by matias on 29/11/19.
//

#ifndef CSVMANAGER_CSVMANAGER_H
#define CSVMANAGER_CSVMANAGER_H

#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class CSVManager {
public:
    static vector<vector<int>> readFile(string file);
};

vector<vector<int>> CSVManager::readFile(string path) {
    vector<vector<int>> retorno;
    ifstream origen(path.c_str());
    if (!origen.is_open())
        cout << "No se pudo abrir el archivo: " << path << endl;
    else
    {
        int i=0;
        while (!origen.eof())
        {
            vector<int> row;
            string linea;
            getline(origen,linea);
            std::stringstream ss(linea);
            for (int i; ss >> i;) {
                row.push_back(i);
                if (ss.peek() == ',')
                    ss.ignore();
            }
            retorno.push_back(row);
        }
    }
    return retorno;
}

#endif //CSVMANAGER_CSVMANAGER_H
