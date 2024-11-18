#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// Funciones para cada operación
double calcularPotencia(double base, int exponente)
{
    double resultado = 1;
    for (int i = 0; i < exponente; i++)
    {
        resultado *= base;
    }
    return resultado;
}

double calcularPendiente(double x1, double y1, double x2, double y2)
{
    if (x2 - x1 == 0)
    {
        cout << "Error: La pendiente es indefinida (división por cero)" << endl;
        return 0;
    }
    return (y2 - y1) / (x2 - x1);
}

void ecuacionCuadraticaReal(double a, double b, double c)
{
    double discriminante = b * b - 4 * a * c;

    if (discriminante >= 0)
    {
        double x1 = (-b + sqrt(discriminante)) / (2 * a);
        double x2 = (-b - sqrt(discriminante)) / (2 * a);
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else
    {
        cout << "Esta ecuación tiene raíces complejas, dirijase a la opcion 4." << endl;
    }
}

void ecuacionCuadraticaCompleja(double a, double b, double c)
{
    double discriminante = b * b - 4 * a * c;

    // Para números complejos, separamos parte real e imaginaria
    double parteReal = -b / (2 * a);
    double parteImaginaria = sqrt(abs(discriminante)) / (2 * a);

    if (discriminante < 0)
    {
        cout << "x1 = " << parteReal << " + " << parteImaginaria << "i" << endl;
        cout << "x2 = " << parteReal << " - " << parteImaginaria << "i" << endl;
    }
    else
    {
        cout << "Esta ecuación tiene raíces reales. Use la opción 3." << endl;
    }
}

void productoCruz(const vector<float> &v1, const vector<float> &v2, vector<float> &resultado)
{
    if (v1.size() != 3 || v2.size() != 3)
        cout << "Ambos vectores tienen que tener una dimension de 3";

    resultado[0] = v1[1] * v2[2] - v1[2] * v2[1];
    resultado[1] = v1[2] * v2[0] - v1[0] * v2[2];
    resultado[2] = v1[0] * v2[1] - v1[1] * v2[0];
}


bool Matriz_es_Simmetrica(const vector<vector<float>>& matriz)
{
   int n = matriz.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matriz[i][j] != matriz[j][i]) 
            {
                return false; // no es simetrica
            }
        }
    }

    return true; // si es simetrica
}



int main()
{
    int opcion;

    do
    {
        // Menú principal
        cout << "\n=== CALCULADORA ===" << endl;
        cout << "1. Calcular potencia" << endl;
        cout << "2. Calcular pendiente" << endl;
        cout << "3. Resolver ecuación cuadrática (reales)" << endl;
        cout << "4. Resolver ecuación cuadrática (complejos)" << endl;
        cout << "5. Producto cruz de dos vectores [3x3]" << endl;
        cout << "6. Determina si una matriz es simetrica" << endl;
        cout << "7. Resolucion de sistemas de ecuaciones de 3 incognitas" << endl;
        cout << "8. Guardas en .txt file " << endl;
        cout << "9. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            double base;
            int exponente;
            cout << "Ingrese la base: ";
            cin >> base;
            cout << "Ingrese el exponente: ";
            cin >> exponente;
            cout << "Resultado: " << calcularPotencia(base, exponente) << endl;
            break;
        }
        case 2:
        {
            double x1, y1, x2, y2;
            cout << "Ingrese x1: ";
            cin >> x1;
            cout << "Ingrese y1: ";
            cin >> y1;
            cout << "Ingrese x2: ";
            cin >> x2;
            cout << "Ingrese y2: ";
            cin >> y2;
            if (x2 != x1)
            {
                cout << "La pendiente es: " << calcularPendiente(x1, y1, x2, y2) << endl;
            }
            break;
        }
        case 3:
        {
            double a, b, c;
            cout << "Ingrese a: ";
            cin >> a;
            cout << "Ingrese b: ";
            cin >> b;
            cout << "Ingrese c: ";
            cin >> c;
            if (a != 0)
            {
                ecuacionCuadraticaReal(a, b, c);
            }
            else
            {
                cout << "Error: 'a' no puede ser cero en una ecuación cuadrática" << endl;
            }
            break;
        }
        case 4:
        {
            double a, b, c;
            cout << "Ingrese a: ";
            cin >> a;
            cout << "Ingrese b: ";
            cin >> b;
            cout << "Ingrese c: ";
            cin >> c;
            if (a != 0)
            {
                ecuacionCuadraticaCompleja(a, b, c);
            }
            else
            {
                cout << "Error: 'a' no puede ser cero en una ecuación cuadrática" << endl;
            }
            break;
        }
        case 5:
        {
            vector<float> v1(3), v2(3), resultado(3);
            for (int i = 0; i < 3; i++)
            {
                cout << "Ingrese el elemento " << i << " del primer vector: ";
                cin >> v1[i];
            }
            for (int i = 0; i < 3; i++)
            {
                cout << "Ingrese el elemento " << i << " del segundo vector: ";
                cin >> v2[i];
            }

            productoCruz(v1, v2, resultado);

            cout << "Producto cruz: (" << resultado[0] << ", " << resultado[1] << ", " << resultado[2] << ")" << endl;

            break;
        }
        case 6:
        {
            int n;
            cout << "Ingrese el tamano de la matriz (n x n): ";
            cin >> n;

            vector<vector<float>> matriz(n, vector<float>(n));

            cout << "Ingrese los elementos de la matriz: " << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << "Elemento " << i << " x " << j << " : ";
                    cin>> matriz[i][j];
                }
            }

            if (Matriz_es_Simmetrica(matriz))
            {
                cout<<"La matriz es simetrica!\n";
            }else{
                cout<<"La matriz no es simetrica!\n";
            }
            break;
        }
        case 9:
            cout << "¡Hasta luego!" << endl;
            break;
        default:
            cout << "Opción no válida" << endl;
        }
    } while (opcion != 9);

    return 0;
}