#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definición de la clase Grafo
class Grafo {
private:
    int V; // Número de nodos
    vector<vector<int>> matriz; // Matriz de adyacencia

public:
    // Constructor
    Grafo(int V) : V(V) {
        matriz.resize(V, vector<int>(V, 0));
    }

    // Método para añadir una arista al grafo
    void agregarArista(int origen, int destino) {
        matriz[origen][destino] = 1;
    }

    // Método para imprimir la matriz de adyacencia
    void imprimirMatriz() {
        cout << "Matriz de adyacencia:" << endl;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Método para encontrar el recorrido más corto utilizando DFS
    void recorridoMasCorto(int origen, int destino) {
        vector<bool> visitado(V, false);
        queue<int> cola;
        vector<int> distancia(V, 0);

        cola.push(origen);
        visitado[origen] = true;

        while (!cola.empty()) {
            int actual = cola.front();
            cola.pop();

            if (actual == destino) {
                cout << "El recorrido mas corto desde " << origen << " hasta " << destino << " es de longitud " << distancia[destino] << endl;
                return;
            }

            for (int i = 0; i < V; ++i) {
                if (matriz[actual][i] == 1 && !visitado[i]) {
                    visitado[i] = true;
                    cola.push(i);
                    distancia[i] = distancia[actual] + 1;
                }
            }
        }

        cout << "No hay camino desde " << origen << " hasta " << destino << endl;
    }
};

int main() {
    Grafo grafo(6);

    // Añadir aristas al grafo
    grafo.agregarArista(0, 1);
    grafo.agregarArista(0, 2);
    grafo.agregarArista(1, 3);
    grafo.agregarArista(2, 4);
    grafo.agregarArista(3, 5);
    grafo.agregarArista(4, 5);

    // Imprimir la matriz de adyacencia
    grafo.imprimirMatriz();

    // Encontrar el recorrido más corto desde el nodo 0 al nodo 5
    grafo.recorridoMasCorto(0, 5);

    return 0;
}
