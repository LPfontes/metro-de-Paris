#include <iostream>
#include <vector>

using namespace std;

// Matriz de distâncias entre as 14 estações
int distancias[14][14] ={
    {0 , 11, 20, 27, 40, 43, 39, 28, 18, 10, 18, 30, 30, 32},
    {11, 0 , 9 , 16, 29, 32, 28, 19, 11, 4, 17, 23, 21, 24},
    {20, 9 , 0 , 7 , 20, 22, 19, 15, 10, 11, 21, 21, 13, 18},
    {27, 16, 7 , 0 , 13, 16, 12, 13, 13, 18, 26, 21, 11, 17},
    {40, 29, 20, 13, 0 , 3 , 2 , 21, 25, 31, 38, 27, 16, 20},
    {43, 32, 22, 16, 3 , 0 , 4 , 23, 28, 33, 41, 30, 17, 20},
    {39, 28, 19, 12, 2 , 4 , 0 , 22, 25, 29, 38, 28, 13, 17},
    {28, 19, 15, 13, 21, 23, 22, 0 , 9 , 22, 18, 7 , 25, 30},
    {18, 11, 10, 13, 25, 28, 25, 9 , 0 , 13, 12, 12, 23, 28},
    {10, 4 , 11, 18, 31, 33, 29, 22, 13, 0 , 20, 27, 20, 23},
    {18, 17, 21, 26, 38, 41, 38, 18, 12, 20, 0 , 15, 35, 39},
    {30, 23, 21, 21, 27, 30, 28, 7 , 12, 27, 15, 0 , 31, 37},
    {30, 21, 13, 11, 16, 17, 13, 25, 23, 20, 35, 31, 0 , 5},
    {32, 24, 18, 17, 20, 20, 17, 30, 28, 23, 39, 37, 5 , 0}
};

// Custo adicional por troca de linha
int custoMudacaDeLinha = 2;

// Classe que representa uma estação no grafo
class Node {
public:
    int id;   
    vector<tuple<Node*, double, int>> conexoes;  // Lista de conexões (estação, custo, linha)

    // Construtor
    Node(int id) {
        this->id = id;
    }

    // Adiciona uma conexão entre estações
    void addConexao(Node* no, double custo, int linha) {
        conexoes.emplace_back(no, custo, linha);
    }
};

// Função que cria as conexões entre as estações
void criarConecoes(Node* estacoes){
    
    estacoes[0].addConexao(&estacoes[1],distancias[0][1],1); //E1

    estacoes[1].addConexao(&estacoes[0],distancias[1][0],1); //E2 E1
    estacoes[1].addConexao(&estacoes[2],distancias[1][2],1); //E2 E3
    estacoes[1].addConexao(&estacoes[8],distancias[1][8],2); //E2 E9
    estacoes[1].addConexao(&estacoes[9],distancias[1][9],2); //E2 E10

    estacoes[2].addConexao(&estacoes[1],distancias[2][1],1); //E3 E2
    estacoes[2].addConexao(&estacoes[3],distancias[2][3],1); //E3 E4
    estacoes[2].addConexao(&estacoes[8],distancias[2][8],3); //E3 E9
    estacoes[2].addConexao(&estacoes[12],distancias[2][12],3); //E3 E13

    estacoes[3].addConexao(&estacoes[2],distancias[3][2],1); //E4 E3
    estacoes[3].addConexao(&estacoes[4],distancias[3][4],1); //E4 E5
    estacoes[3].addConexao(&estacoes[7],distancias[3][7],4); //E4 E8
    estacoes[3].addConexao(&estacoes[12],distancias[3][12],4); //E4 E13

    estacoes[4].addConexao(&estacoes[3],distancias[4][3],1); //E5 E4
    estacoes[4].addConexao(&estacoes[5],distancias[4][5],1); //E5 E6
    estacoes[4].addConexao(&estacoes[6],distancias[4][6],2); //E5 E7
    estacoes[4].addConexao(&estacoes[7],distancias[4][7],2); //E5 E8

    estacoes[5].addConexao(&estacoes[4],distancias[5][4],1); //E6 E5
    
    estacoes[6].addConexao(&estacoes[4],distancias[6][4],2); //E7 E5

    estacoes[7].addConexao(&estacoes[3],distancias[7][3],4); //E8 E4
    estacoes[7].addConexao(&estacoes[4],distancias[7][4],2); //E8 E5
    estacoes[7].addConexao(&estacoes[8],distancias[7][8],2); //E8 E9
    estacoes[7].addConexao(&estacoes[11],distancias[7][11],4); //E8 E12

    estacoes[8].addConexao(&estacoes[1],distancias[8][1],2); //E9 E2
    estacoes[8].addConexao(&estacoes[2],distancias[8][2],3); //E9 E3
    estacoes[8].addConexao(&estacoes[7],distancias[8][7],2); //E9 E8
    estacoes[8].addConexao(&estacoes[10],distancias[8][10],3); //E9 E11

    estacoes[9].addConexao(&estacoes[1],distancias[9][1],2); //E10 E2

    estacoes[10].addConexao(&estacoes[8],distancias[10][8],3); //E11 E9

    estacoes[11].addConexao(&estacoes[7],distancias[11][7],4); //E12 E8

    estacoes[12].addConexao(&estacoes[2],distancias[12][2],3); //E13 E3
    estacoes[12].addConexao(&estacoes[3],distancias[12][3],4); //E13 E4
    estacoes[12].addConexao(&estacoes[13],distancias[12][13],4); //E13 E14
    
    estacoes[13].addConexao(&estacoes[12],distancias[13][12],4); //E14 E13
}

// Função para encontrar a próxima estação a ser visitada
Node* buscaProximaEstacao(Node* estacoes, int estacaoAtual, int estacaoDestino, double* custoAcumulado, int* linhaAtual) {
    int CustoTotal[4]; // Vetor para armazenar os custos das conexões
    int menorCusto = 999999; // Inicializa com um valor alto
    int mundacaDeLinha = 0;
    int proximaLinha = *linhaAtual;
    Node* proximaEstacao = nullptr;
    int i = 0;

    // Itera sobre as conexões da estação atual
    for (auto [no, custo, linha] : estacoes[estacaoAtual].conexoes) {
        // Verifica se há troca de linha e adiciona o custo extra se necessário
        mundacaDeLinha = *linhaAtual != linha ? custoMudacaDeLinha : 0;

        // Calcula o custo total (caminho percorrido + heurística + possível troca de linha)
        CustoTotal[i] = *custoAcumulado + custo + distancias[no->id][estacaoDestino] + mundacaDeLinha;

        // Verifica se o custo encontrado é menor que o atual mínimo
        if (CustoTotal[i] < menorCusto) {
            menorCusto = CustoTotal[i];
            proximaEstacao = no;
            proximaLinha = linha;
        }
        i++;
    }

    // Atualiza os custos e linha atual
    mundacaDeLinha = *linhaAtual != proximaLinha ? custoMudacaDeLinha : 0;
    *linhaAtual = proximaLinha;
    *custoAcumulado += distancias[estacaoAtual][proximaEstacao->id] + mundacaDeLinha;

    return proximaEstacao; // Retorna a próxima estação a ser visitada
}

int main() {
    // Criação das estações
    Node estacoes[14] = {
        Node(0), Node(1), Node(2), Node(3), Node(4), Node(5), Node(6),
        Node(7), Node(8), Node(9), Node(10), Node(11), Node(12), Node(13)
    };

    // Inicializa o custo acumulado
    double custoAcumulado = 0;
    
    // Criação das conexões entre as estações
    criarConecoes(estacoes);

    // Definição da estação inicial e de destino
    int estacaoInicial = 0;  // Estação de partida (E1)
    int linhaAtual = 1;       // Linha inicial
    int estacaoDestino = 11;  // Estação de destino (E12)
    
    // Ponteiro para acompanhar a estação atual no percurso
    Node* estacaoAtual = &estacoes[estacaoInicial];

    // Impressão do caminho percorrido
    cout << "Caminho: " << estacaoAtual->id + 1; // Exibe a estação inicial
    while (estacaoAtual->id != estacaoDestino) {
        estacaoAtual = buscaProximaEstacao(estacoes, estacaoAtual->id, estacaoDestino, &custoAcumulado, &linhaAtual);
        cout << " -> " << estacaoAtual->id + 1; // Exibe a próxima estação
    }

    // Exibe o custo total do trajeto
    cout << "\nCusto total: " << custoAcumulado << endl;

    return 0;
}
