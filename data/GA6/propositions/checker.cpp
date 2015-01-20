#include "testlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h> 

using namespace std;
typedef long long ll;
typedef double lf;
typedef long double llf;
typedef unsigned long long llu;

const int maxn = 200000;
int i, n, tru, a[maxn + 10];
char c, s[maxn];
string ja, pa;

int main(int argc, char * argv[]) {
	registerTestlibCmd(argc, argv);

	n = inf.readInt();
	inf.readEoln();
	for (int i = 1; i <= n; i++) {
		string s = inf.readLine();
		if (s[0] == 'T') a[i] = 1;
		else if (s[0] == 'F') a[i] = 2;
		else a[i] = -atoi(s.c_str());
	}

	inf.readEof();

	ja = ans.readLine();
	pa = ouf.readLine();
	if (pa != "POSSIBLE" && pa != "IMPOSSIBLE") {
		quit(_pe, "ù ��° �ٿ� POSSIBLE �Ǵ� IMPOSSIBLE�� ������� �ʾҽ��ϴ�.");
	}

	if (pa == "IMPOSSIBLE") {
		if (ja == "IMPOSSIBLE") quit(_ok, "");
		else quit(_wa, "");
	}

	for (int i = 1; i <= n; i++) {
		string v = ouf.readLine();
		if (v == "true") s[i] = 't'; else if (v == "false") s[i] = 'f';
		else quit(_pe, "'true' �Ǵ� 'false'�� ������� �ʾҽ��ϴ�.");
	}
	ouf.readEof();

	for (int i = 1; i <= n; i++) {
		if (s[i] == 't') ++tru;
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] <= 0) {
			if (s[i] == 't' && a[i] != -tru) quit(_wa, "����� �����մϴ�");
			if (s[i] == 'f' && a[i] == -tru) quit(_wa, "����� �����մϴ�");
		}
		else {
			if (s[i] == 't' && a[i] == 1 && s[i % n + 1] == 'f') quit(_wa, "����� �����մϴ�");
			if (s[i] == 't' && a[i] == 2 && s[i % n + 1] == 't') quit(_wa, "����� �����մϴ�");
			if (s[i] == 'f' && a[i] == 1 && s[i % n + 1] == 't') quit(_wa, "����� �����մϴ�");
			if (s[i] == 'f' && a[i] == 2 && s[i % n + 1] == 'f') quit(_wa, "����� �����մϴ�");
		}
	}

	if (ja == "IMPOSSIBLE") {
		quit(_fail, "���� �� ���� ������ �����Ѵٰ� �մϴ�. ���߾��.. ��ڿ��� �˷��ּ���");
	}

	quit(_ok, "");
	quitf(_ok, "good");
	return 0;
}