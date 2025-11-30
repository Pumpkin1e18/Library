#include <bits/stdc++.h>
using namespace std;

// 座標圧縮
template<class T>
class Compress {
public:
    map<T, int> zip;
    vector<T> unzip;

    vector<int> compress(vector<T> &x) {
        unzip = x;
        sort(all(unzip));
        unzip.erase(unique(all(unzip)), unzip.end());

        zip.clear();
        rep(i,unzip.size()) zip[unzip[i]] = i;

        vector<int> zipped;
        for (auto v : x) zipped.push_back(zip[v]);
        return zipped;
    }
};

// Compress<int> compress;
// vector<int> v {6, 3, -2, 3, 7};
// vector<int> av = compress.compress(v);  // 2, 1, 0, 1, 3
// auto unzip = commpress.unzip;  // -2, 3, 6, 7
// unzip[av[0]]  // unzip[2] = 6



// ランダムな値を逐次 0,1,2,... にマッピングするライブラリ
// T は int, long long, string など unordered_map のキーに使える型
template <class T>
class IdMapper {
public:
    unordered_map<T, int> mp;  // 値 -> ID
    vector<T> rev;             // ID -> 値

    // x に対応する ID を返す（存在しない場合、新しいIDを割り当てる）
    int get_id(const T &x) {
        if (zip(x) != -1) return zip(x);
        mp[x] = rev.size(); rev.push_back(x);
        return zip(x);
    }
    int zip(const T &x) {
        auto it = mp.find(x);
        if (it == mp.end()) return -1;
        return it->second;  // 元の値 -> ID （存在しない場合は -1 を返す）
    }
    const T &unzip(int id) {
        return rev[id];  // ID -> 元の値
    }

    bool has(const T &x) { return mp.find(x) != mp.end(); }
    int size() const { return (int)rev.size(); }
    const vector<T> &unzip_table() { return rev; }
    const unordered_map<T,int> &zip_table() { return mp; }
    void clear() { mp.clear(); rev.clear(); }
};

// IdMapper<int> mapper;
// mapper.get_id(5);  // 0
// mapper.get_id(-10);  // 1
// mapper.zip(5);  // 0
// mapper.zip(0);  // -1
// mapper.unzip(1)  // -10
