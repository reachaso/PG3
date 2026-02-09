#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>
#include <chrono>

using namespace std;

// タイルIDを表示用の文字に変換する
static char tile_to_char(int id) {
  switch (id) {
  case 0: return '0';
  case 1: return '1';
  }
}

// CSVファイルを読み込み、2次元配列として格納する
static void load_csv_map(const string& path,
  vector<vector<int>>& out_map,
  mutex& out_mutex,
  atomic<bool>& loaded)
{
  vector<vector<int>> temp;
  ifstream file(path);
  string line;

  // 1行ずつ読み込む
  while (getline(file, line)) {
    vector<int> row;
    stringstream ss(line);
    string cell;

    // カンマ区切りで数値を取得
    while (getline(ss, cell, ',')) {
      try {
        row.push_back(stoi(cell));
      } catch (...) {
        row.push_back(0);
      }
    }

    if (!row.empty()) {
      temp.push_back(row);
    }
  }

  // 共有データに書き込む（排他制御）
  {
    lock_guard<mutex> lock(out_mutex);
    out_map = temp;
  }
  loaded = true;
}

int main() {

  const string csv_path = "map.csv";

  vector<vector<int>> map;
  mutex map_mutex;
  atomic<bool> loaded(false);

  // CSV読み込みスレッドを開始
  thread loader(load_csv_map, csv_path, ref(map), ref(map_mutex), ref(loaded));

  // 読み込み完了を待機
  while (!loaded) {
    fflush(stdout);
    this_thread::sleep_for(chrono::milliseconds(100));
  }

  // 読み込んだマップを表示
  {
    lock_guard<mutex> lock(map_mutex);
    for (size_t y = 0; y < map.size(); ++y) {
      for (size_t x = 0; x < map[y].size(); ++x) {
        printf("%c", tile_to_char(map[y][x]));
      }
      printf("\n");
    }
  }

  loader.join();

  return 0;
}
