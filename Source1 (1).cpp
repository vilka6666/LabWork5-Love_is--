#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <locale.h>

using namespace std;

// ������� ��� ������ ������������� ������ (����nf � �������� ���������)
vector<int> findIsolatedVertices(const vector<vector<int>>& adjacency_matrix) {
    vector<int> isolated_vertices;
    for (int i = 1; i < adjacency_matrix.size(); ++i) {
        bool isolated = true;
        for (int j = 1; j < adjacency_matrix[i].size(); ++j) {
            if (adjacency_matrix[i][j] == 1) {
                isolated = false;
                break;
            }
        }
        if (isolated) {
            isolated_vertices.push_back(i);
        }
    }
    return isolated_vertices;
}

// ������� ��� ������ �������� ������ (������ � �������� ���������)
vector<int> findLeafVertices(const vector<vector<int>>& adjacency_matrix) {
    vector<int> leaf_vertices;
    for (int i = 1; i < adjacency_matrix.size(); ++i) {
        int degree = 0;
        for (int j = 1; j < adjacency_matrix[i].size(); ++j) {
            if (adjacency_matrix[i][j] == 1) {
                degree++;
            }
        }
        if (degree == 1) {
            leaf_vertices.push_back(i);
        }
    }
    return leaf_vertices;
}

// ������� ��� ������ ������������ ������ (������ � �������� ���������)
vector<int> findDominatingVertices(const vector<vector<int>>& adjacency_matrix) {
    vector<int> dominating_vertices;
    for (int i = 1; i < adjacency_matrix.size(); ++i) {
        bool dominating = true;
        for (int j = 1; j < adjacency_matrix[i].size(); ++j) {
            if (i != j && adjacency_matrix[i][j] != 1) {
                dominating = false;
                break;
            }
        }
        if (dominating) {
            dominating_vertices.push_back(i);
        }
    }
    return dominating_vertices;
}

// ������� ��� �������� � ������ ������� ������������� 
vector < vector < int>> createAndPrintIncidenceMatrix(const vector < vector < int>>& adjacency_matrix, int num_edges) {
    vector < vector < int>> incidence_matrix(adjacency_matrix.size(), vector<int>(num_edges, 0));
    int edge_idx = 0;
    for (int i = 1; i < adjacency_matrix.size(); ++i) {
        for (int j = i + 1; j < adjacency_matrix[i].size(); ++j) {
            if (adjacency_matrix[i][j] == 1) {
                incidence_matrix[i][edge_idx] = 1;
                incidence_matrix[j][edge_idx] = 1;
                edge_idx++;
            }
        }
    }

    printf("������� �������������:\n");
    for (int i = 1; i < incidence_matrix.size(); ++i) {
        for (int j = 0; j < num_edges; ++j) {
            printf("%d ", incidence_matrix[i][j]);
        }
        printf("\n");
    }
    return incidence_matrix;
}

int getGraphSizeFromIncidenceMatrix(const vector < vector < int>>& incidence_matrix) {
    // ���������� ���������� �������� � ������� �������������, ��� �������� �������� �����
    return incidence_matrix[0].size(); // ��������������, ��� ������� �� �����
}

void printIncidenceMatrixDimensions(int num_vertices, int num_edges) {
    printf("����������� ������� �������������: %d x %d\n", num_vertices, num_edges);
}

//������� ��� ������ ������������� ������ �� ������ ������� �������������
vector<int> findIsolatedVerticesIncidence(const vector < vector < int>>& incidence_matrix) {
    vector<int> isolated_vertices;
    for (int i = 0; i < incidence_matrix.size(); ++i) {
        bool isolated = true;
        for (int j = 0; j < incidence_matrix[i].size(); ++j) {
            if (incidence_matrix[i][j] != 0) {
                isolated = false;
                break;
            }
        }
        if (isolated) {
            isolated_vertices.push_back(i);
        }
    }
    return isolated_vertices;
}

//������� ��� ������ �������� ������ �� ������ ������� �������������
vector<int> findLeafVerticesIncidence(const vector < vector < int>>& incidence_matrix) {
    vector<int> leaf_vertices;
    for (int i = 1; i < incidence_matrix.size(); ++i) {
        int degree = 0;
        for (int j = 0; j < incidence_matrix[i].size(); ++j) {
            if (incidence_matrix[i][j] != 0) {
                degree++;
            }
        }
        if (degree == 1) {
            leaf_vertices.push_back(i);
        }
    }
    return leaf_vertices;
}

// ������� ��� ������ ������������ ������ �� ������ ������� �������������
vector<int> findDominatingVerticesIncidence(const vector < vector < int>>& incidence_matrix) {
    vector<int> dominating_vertices;
    int total_vertices = incidence_matrix.size();
    for (int i = 1; i < incidence_matrix.size(); ++i) {
        int edge_count = 0;
        for (int j = 1; j < incidence_matrix[i].size(); ++j) {
            if (incidence_matrix[i][j] != 1) {
                edge_count++;
            }
        }
        if (edge_count == total_vertices - 1) {
            dominating_vertices.push_back(i);
        }
    }
    return dominating_vertices;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int num_vertices;
    double edge_probability;

    printf("������� ���������� ������ � �����: ");
    scanf("%d", &num_vertices);

    printf("������� ����������� ������� ����� (0 - 1): ");
    scanf("%lf", &edge_probability);

    srand(static_cast<unsigned int>(time(nullptr)));

    vector<vector<int>> adjacency_matrix(num_vertices + 1, vector<int>(num_vertices + 1, 0));
    int num_edges = 0;
    for (int i = 1; i <= num_vertices; ++i) {
        for (int j = i + 1; j <= num_vertices; ++j) {
            if (static_cast<double>(rand()) / RAND_MAX < edge_probability) {
                adjacency_matrix[i][j] = 1;
                adjacency_matrix[j][i] = 1;
                num_edges++;
            }
        }
    }

    printf("������� ���������:\n");
    for (int i = 1; i <= num_vertices; ++i) {
        for (int j = 1; j <= num_vertices; ++j) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }

    printf("���������� ������: %d\n", num_vertices);
    printf("���������� ����: %d\n", num_edges);

    vector<int> isolated_vertices = findIsolatedVertices(adjacency_matrix);
    if (!isolated_vertices.empty()) {
        printf("������������� ������� (������� ���������):");
        for (int i = 0; i < isolated_vertices.size(); ++i) {
            printf(" %d", isolated_vertices[i]);
        }
        printf("\n");
    }
    else {
        printf("��� ������������� ������ (������� ���������).\n");
    }

    vector<int> leaf_vertices = findLeafVertices(adjacency_matrix);
    if (!leaf_vertices.empty()) {
        printf("�������� ������� (������� ���������):");
        for (int i = 0; i < leaf_vertices.size(); ++i) {
            printf(" %d", leaf_vertices[i]);
        }
        printf("\n");
    }
    else {
        printf("��� �������� ������ (������� ���������).\n");
    }

    vector<int> dominating_vertices = findDominatingVertices(adjacency_matrix);
    if (!dominating_vertices.empty()) {
        printf("������������ ������� (������� ���������):");
        for (int i = 0; i < dominating_vertices.size(); ++i) {
            printf(" %d", dominating_vertices[i]);
        }
        printf("\n");
    }
    else {
        printf("��� ������������ ������ (������� ���������).\n\n\n");
    }

    // createAndPrintIncidenceMatrix(adjacency_matrix, num_edges);
    printIncidenceMatrixDimensions(num_vertices, num_edges);
    vector < vector < int>> incidence_matrix = createAndPrintIncidenceMatrix(adjacency_matrix, num_edges);
    vector<int> isolated_vertices_incidence = findIsolatedVerticesIncidence(incidence_matrix);

    // ����������� ������� �����
    int graph_size = getGraphSizeFromIncidenceMatrix(incidence_matrix);
    printf("������ �����: %d\n", graph_size);

    if (!isolated_vertices_incidence.empty()) {
        printf("������������� ������� (������� �������������):");
        for (int vertex : isolated_vertices_incidence) {
            printf(" %d", vertex);
        }
        printf("\n");
    }
    else {
        printf("��� ������������� ������ (������� �������������).\n");
    }

    vector<int> leaf_vertices_incidence = findLeafVerticesIncidence(incidence_matrix);
    if (!leaf_vertices_incidence.empty()) {
        printf("�������� ������� (������� �������������):");
        for (int vertex : leaf_vertices_incidence) {
            printf(" %d", vertex);
        }
        printf("\n");
    }
    else {
        printf("��� �������� ������ (������� �������������).\n");
    }

   
    if (!dominating_vertices.empty()) {
        printf("������������ ������� (������� �������������):");
        for (int i = 0; i < dominating_vertices.size(); ++i) {
            printf(" %d", dominating_vertices[i]);
        }
        printf("\n");
    }
    else {
        printf("��� ������������ ������ (������� �������������).\n\n\n");
    }


    return 0;
}
