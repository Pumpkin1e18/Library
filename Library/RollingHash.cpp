/* ローリングハッシュ */
// 前計算量：O(n)
// 区間 [l,r) のハッシュ取得計算量：O(1)

// 文字列の部分文字列のハッシュ値を高速に計算する
// 部分文字列の一致判定をハッシュ比較することで O(1) で行える
// 前の区間のハッシュ値から1文字削って1文字足すだけで新しい区間のハッシュが O(1) で求まる

// ハッシュ
// B：基数、M：法
// S = abcde（ハッシュとして計算するときはASCIIコードで計算）
// H：先頭からi文字のハッシュ
// H[1] = a
// H[2] = aB + b
// H[3] = aB^2 + bB + c
// cdのハッシュ：hash(2,4) = H[4] - H[2]B^2
//                         = (aB^3 + bB^2 + cB + d) - (aB^3 + bB^2)
//                         = cB + d
// 一般に hash(l,r) = H[r] - H[l]B^(r-l)


using ll = long long;


class RollingHash {
    static const ll base1 = 1009;
    static const ll base2 = 2009;
    static const ll mod1 = 1000000007;
    static const ll mod2 = 1000000009;
    vector<ll> hash1, hash2, pow1, pow2;

public:
    RollingHash(const string &s) {
        int n = s.size();
        hash1.assign(n + 1, 0);
        hash2.assign(n + 1, 0);
        pow1.assign(n + 1, 1);
        pow2.assign(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            hash1[i + 1] = (hash1[i] * base1 + s[i]) % mod1;
            hash2[i + 1] = (hash2[i] * base2 + s[i]) % mod2;
            pow1[i + 1] = (pow1[i] * base1) % mod1;
            pow2[i + 1] = (pow2[i] * base2) % mod2;
        }
    }
    
    pair<ll, ll> hash() const {
        return get(0, hash1.size() - 1);
    }
    
    // [l, r)
    pair<ll, ll> match(int l, int r) const {
        ll res1 = ((hash1[r] - hash1[l] * pow1[r - l]) % mod1 + mod1) % mod1;
        ll res2 = ((hash2[r] - hash2[l] * pow2[r - l]) % mod2 + mod2) % mod2;
        return make_pair(res1, res2);
    }
};