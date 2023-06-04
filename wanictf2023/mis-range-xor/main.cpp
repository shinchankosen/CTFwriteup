#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
#define rep(i, n) for(int i=0;i<n;i++)
#define all(i, v) for(auto& i : v)
typedef long long ll;
using namespace std;
const ll MOD7 = 1000000007, MOD998 = 998244353, INF = (1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

template<int MOD> struct Modint {
    long long val;
    constexpr Modint(long long v = 0) noexcept : val(v % MOD) { if (val < 0) val += MOD; }
    constexpr int mod() const { return MOD; }
    constexpr Modint operator - () const noexcept { return val ? MOD - val : 0; }
    constexpr Modint operator + (const Modint& r) const noexcept { return Modint(*this) += r; }
    constexpr Modint operator - (const Modint& r) const noexcept { return Modint(*this) -= r; }
    constexpr Modint operator * (const Modint& r) const noexcept { return Modint(*this) *= r; }
    constexpr Modint operator / (const Modint& r) const noexcept { return Modint(*this) /= r; }
    constexpr Modint& operator += (const Modint& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Modint& operator -= (const Modint& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Modint& operator *= (const Modint& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Modint& operator /= (const Modint& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b, swap(a, b);
            u -= t * v, swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Modint& r) const noexcept { return this->val == r.val; }
    constexpr bool operator != (const Modint& r) const noexcept { return this->val != r.val; }
    friend constexpr istream& operator >> (istream& is, Modint<MOD>& x) noexcept {
        is >> x.val;
        x.val %= MOD;
        if (x.val < 0) x.val += MOD;
        return is;
    }
    friend constexpr ostream& operator << (ostream& os, const Modint<MOD>& x) noexcept {
        return os << x.val;
    }
    constexpr Modint<MOD> pow(long long n) noexcept {
        if (n == 0) return 1;
        if (n < 0) return this->pow(-n).inv();
        Modint<MOD> ret = pow(n >> 1);
        ret *= ret;
        if (n & 1) ret *= *this;
        return ret;
    }
    constexpr Modint<MOD> inv() noexcept {
        long long a = this->val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b, swap(a, b);
            u -= t * v, swap(u, v);
        }
        return Modint<MOD>(u);
    }
};

const int MOD = MOD7;
using mint = Modint<MOD>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n = 1000;
    vector<mint> dp1(1024, 0);
    vector<int> dp2(1024, 0);
    dp1[0] = 1;
    dp2[0] = 1;

    rep(i, n) {
        int a;
        cin >> a;
        vector<mint> nx1(1024, 0);
        vector<int> nx2(1024, 0);
        int num = min(a, 1000 - a);
        for(int j = 0; j < 1024; j ++) {
            nx1[j ^ a] += dp1[j];
            nx2[j ^ a] |= dp2[j];
            if(num != a) {
                swap(num, a);
                nx1[j ^ a] += dp1[j];
                nx2[j ^ a] |= dp2[j];
            }
        }
        swap(nx1, dp1);
        swap(nx2, dp2);
    }
    for(int i = 0; i < 1024; i ++) {
        if(dp2[i]) {
            cout << dp1[i].val << endl;
            return 0;
        }
    }

    return 0;
}
