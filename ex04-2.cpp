#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cout << "r: register, p: print" << std::endl;
    // ① 商品名，単価，個数の情報を格納するvector型の変数items，prices，qtiesを宣言する．
    std::vector<std::string> items;
    std::vector<int> prices;
    std::vector<int> qties;


    // 入力が失敗するまで一文字のコマンドを受け取るループを作成する
    for (char c; std::cin >> c;) {
        switch (c) {
            // ② rが入力された場合は商品の登録処理を行う
            case 'r':
            {
                std::cout << "item price qty: ";
                std::string item;
                int price, qty;
                // 商品名，単価，個数の情報を入力させる．入力が失敗した場合は登録処理を中断する
                if (!(std::cin >> item >> price >> qty))
                    break;
                // 2-1 繰り返し処理を用いて登録されている商品名を探索する
                int i{};
                for (;i<items.size();i++) {
                    if (items[i]==item) break;
                }
                // 商品名が既に登録されていれば登録されている単価，個数の情報を新しい情報で更新する
                if (i < items.size()) {
                    prices[i] = price;
                    qties[i] = qty;
                    break;
                }

                // 2-2 items，prices，qtiesに情報を追加する
                items.push_back(item);
                prices.push_back(price);
                qties.push_back(qty);
                break;
            }
            // ③ pが入力された場合は注文票を出力する
            case 'p':
            {
                int total{};
                // 3-1 「商品名 単価 個数」を表示させる
                // さらに、totalを用いて合計金額を計算する
                for (int i=0; i<items.size(); i++){
                    std::cout << items[i] << " " << prices[i] << " " << qties[i] << "\n";
                    total+=prices[i]*qties[i];
                }

                std::cout << "total: " << total << std::endl;
                break;
            }
            // その他の文字が入力された場合は「Unknown command.」と出力する
            default:
                std::cout << "Unknown command." << std::endl;
        }
    }
}