#include <iostream>
#include <iterator>
#include <list>
#include <stdio.h>

using namespace std;

int main() {
  // 山手線の駅名を英語表記で双方向リストに格納
  list<const char *> yamanoteLineStations = {
      "Tokyo",        "Kanda",     "Akihabara", "Okachimachi",  "Ueno",
      "Uguisudani",   "Nippori",   "Tabata",    "Komagome",     "Sugamo",
      "Otsuka",       "Ikebukuro", "Mejiro",    "Takadanobaba", "Shin-Okubo",
      "Shinjuku",     "Yoyogi",    "Harajuku",  "Shibuya",      "Ebisu",
      "Meguro",       "Gotanda",   "Osaki",     "Shinagawa",    "Tamachi",
      "Hamamatsucho", "Shimbashi", "Yurakucho"};

  printf("[山手線の駅名一覧 : 1970年]\n");
  for (list<const char *>::iterator it = yamanoteLineStations.begin();
       it != yamanoteLineStations.end(); ++it) {
    cout << *it << '\n';
  }

  printf("\n[山手線の駅名一覧 : 2019年]\n");
  // 西日暮里駅を追加
  yamanoteLineStations.insert(next(yamanoteLineStations.begin(), 7),
                              "Nishi-Nippori");
  for (list<const char *>::iterator it = yamanoteLineStations.begin();
       it != yamanoteLineStations.end(); ++it) {
    cout << *it << '\n';
  }

  printf("\n[山手線の駅名一覧 : 2022年]\n");
  // 高輪ゲートウェイ駅を追加
  yamanoteLineStations.insert(next(yamanoteLineStations.begin(), 25),
                              "Takanawa Gateway");
  for (list<const char *>::iterator it = yamanoteLineStations.begin();
       it != yamanoteLineStations.end(); ++it) {
    cout << *it << '\n';
  }

  return 0;
}
