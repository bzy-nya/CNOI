#include<bits/stdc++.h>
using namespace std;

int Query(int x);

void init() {}

int dq(int x) { return 1 << (int)floor( log2(x) ); }

int dh(int x) { 
    int y = dq(x);
    if( x - y >= y / 2 ) y += y / 2;
    return y;
}

pair<int,int> Guess(int n, int c) {
    int l = 1, r = n;
    while(l < r) {
        int pt = l + dh(r - l + 1) - 1;
        int X = Query(pt);
        if( !X ) break;
        if( X < 0 ) l = pt + 1;
        if( X > 0 ) r = pt - 1;
    }
    int md = l + dh(r - l + 1) - 1;
    int pl = md - 1;
    while( l <= pl ) {
        int pt = pl - dq(pl - l + 1) + 1;
        if( !Query(pt) ) pl = pt - 1;
        else l = pt + 1;
    }
    int pr = md + 1;
    while( r >= pr ) {
        int pt = pr + dq(r - pr + 1) - 1;
        if( !Query(pt) ) pr = pt + 1;
        else r = pt - 1;
    }
    return make_pair( l, r );
}