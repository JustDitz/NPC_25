#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

// Fungsi untuk mengubah kata menjadi angka
int codeToNumber(const string& code) {
    if (code == "wa") return 1;
    if (code == "wi") return 2;
    if (code == "wu") return 3;
    if (code == "we") return 4;
    if (code == "wo") return 0;
    return -1; // Tidak valid
}

// Fungsi untuk membangun Sandi Utama
vector<int> buildMainCode(int X) {
    vector<int> mainCode;

    for (int i = 1; i <= X; i++) {
        mainCode.push_back(__builtin_popcount(i) % 5);    
    }
    
    return vector<int>(mainCode.begin(), mainCode.begin() + X);
}

// Fungsi untuk mencari subarray
bool findSubarray(const vector<int>& mainCode, const vector<int>& secretCode, int& indexSum) {
    int n = secretCode.size();
    int m = mainCode.size();

    for (int i = 0; i <= m - n; ++i) {
        bool found = true;
        indexSum = 0;
        for (int j = 0; j < n; ++j) {
            if (mainCode[i + j] != secretCode[j]) {
                found = false;
                break;
            }
            indexSum += (i + j + 1); // 1-based index
        }
        if (found) return true;
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    vector<string>ans;

    while (T--) {
        int N, X;
        cin >> N >> X;

        vector<int> secretCode(N);
        for (int i = 0; i < N; ++i) {
            string code;
            cin >> code;
            secretCode[i] = codeToNumber(code);
        }

        vector<int> mainCode = buildMainCode(X);
        int indexSum = 0;

        if (findSubarray(mainCode, secretCode, indexSum)) {
            ans.push_back("Selamat Datang Agen " + to_string(indexSum));
        } else {
            ans.push_back("Dasar Penyusup");
        }
    }

    for (auto i: ans) {
        cout << i << endl;
    }

    return 0;
}
