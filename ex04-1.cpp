#include <iostream>
#include <string>
#include <vector>

int main() {
    // ① string型を要素として持つvector型の変数strsを宣言し，
    // "seikei"，"university"，"c++"，"programming"，"2024"で初期化する
    std::vector<std::string> strs{"seikei","university","c++","programming","2024"};

    // ② 範囲for文を用いて、strsのすべての要素を標準出力する
    for (std::string i : strs) std::cout << i << " ";

    std::cout << "\n\n";

    // ③ for文を用いて、i番目の文字列を出力し、
    // さらに、iが偶数のときは「一文字の空白」を出力し、
    // iが奇数のときは「i番目の文字列と改行」を出力する
    for (int i=0; i<strs.size(); i++){
        std::cout << (i%2==0 ? "\n" : " ") << strs[i];
    }

    std::cout << "\n";
    return 0;
}