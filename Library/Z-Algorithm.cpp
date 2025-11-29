/*Z-Algorithm*/

// 説明
// ある文字列 S が与えられているとする。
// Z-Algorithm では, それぞれの i (0 ≦ i ≺ |S|) について S と S[i,|S|)の最長共通接頭辞の長さを記録した配列を線形時間で構築するアルゴリズムである。
// 具体例を以下に示す。例えば i=4 のときの最長共通接頭辞は “aaa”, つまり 3 文字である。
// index  0 1 2 3 4 5 6 7 8
//   s    a a a z a a a a z
// prefix 9 2 1 0 3 4 2 1 0 ← これを高速に求める
// https://ei1333.github.io/luzhiled/snippets/string/z-algorithm.htmlより引用

// アルゴリズム詳細説明 https://www.creativ.xyz/arc055c-410
// 計算量：O(|S|)
// for 中の 1 番目の if の中は前の計算結果を使って計算可能
// i + prefix[i-j] == j + prefix[j] の時伸びる可能性がある ・・・ Ⅰ
// i + prefix[i-j] == j + prefix[j] の時伸びる可能性はない ・・・ Ⅱ
// i + prefix[i-j] == j + prefix[j] の時、前の計算結果を使う ・・・ Ⅲ
// Ⅰ の時と Ⅱ の時を分けてもいいが j + prefix[j] は小さくならないのでまとめてる
// j + prefix[j] が単調増加なので O(|S|)

#define int long long


vector<int> z_algorithm(const string &s) {
  vector<int> prefix(s.size());
  for(int i = 1, j = 0; i < s.size(); i++) {
    if(i + prefix[i-j] < j + prefix[j]) {
      prefix[i] = prefix[i - j];
    }else{
      int k = max(0LL, j + prefix[j] - i);    // ← long long なことに注意
      while(i + k < s.size() && s[k] == s[i+k]) k++;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = (int) s.size();
  return prefix;
}