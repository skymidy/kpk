#include <iostream>
#include <vector>

int transitions[1001][1001];
bool isChecked[1001];

std::vector<int> origins;
std::vector<std::pair<int, int>> edges;

bool dfs(int node, int n) {

    isChecked[node] = true;
    for (int j = 1; j < n+1; ++j) {
        if (!isChecked[j] && transitions[node][j] == 1) {
            dfs(j, n);
            edges.emplace_back(node, j);
        }
    }

}

void solution(FILE *src, FILE *dest) {

    int n, m;

    fscanf(src, "%d %d", &n, &m);

//    std::vector<std::vector<int>> transitions(n + 1);

    int ni, mi;
    for (int i = 0; i < m; ++i) {
        fscanf(src, "%d %d", &ni, &mi);
        transitions[ni][mi] = 1;
        transitions[mi][ni] = 1;
    }

    for (int i = 1; i < n + 1; ++i) {
        if (!isChecked[i] ) {
            dfs(i, n);
            origins.push_back(i);
        }
    }

    fprintf(dest, "%d\n", (int) edges.size());
    for (int i = 0; i < edges.size(); ++i) {
        fprintf(dest, "%d %d\n", edges[i].first, edges[i].second);
    }

    fprintf(dest, "%d\n", (int) origins.size() - 1);
    for (int i = 0; i < origins.size() - 1; ++i) {
        fprintf(dest, "%d %d\n", origins[i], origins[i+1]);
    }

}

int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");

    solution(in, out);
    fclose(in);
    fclose(out);
    return 0;
}
