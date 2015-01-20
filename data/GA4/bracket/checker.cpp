#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>

using namespace std;
typedef long long ll;

void ERROR(const char* str) {
	printf("Incorrect - %s", str);
	exit(0);
}

int N, Q;
char CST[20], USRCST[20];
char S[200005], E[200005];

int main(int argc, char *argv[]){
	FILE *in = fopen(argv[1], "r");
	FILE *out = fopen(argv[2], "r");
	FILE *usrout = fopen(argv[3], "r");

	int i;

	if (fscanf(in, "%d%s", &N, S + 1) != 2) ERROR("??A");
	if (fscanf(out, "%s", CST) != 1) ERROR("??B");
	if (fscanf(usrout, "%s%s", USRCST, E + 1) != 2) ERROR("��� ������ �ٽ� ���캸����");

	if (strcmp(CST, USRCST)) {
		ERROR("����� ����� �ٸ��ϴ�.");
	}

	if (strcmp(USRCST, "WRONG")) {
		ll cost; sscanf(USRCST, "%lld", &cost);
		if ((int)strlen(E + 1) != N) ERROR("������ ��ȣ���� ���̰� N�� �ٸ��ϴ�.");
		int depth = 0;

		ll tcost = 0;
		for (i = 1; i <= N; i++) {
			if (S[i] == '(') {
				++depth;
				if (E[i] != '(') ERROR("���� '('�� �ִ� �ڸ��� �ٸ� ���ڰ� �ֽ��ϴ�.");
			}
			else if (S[i] == ')') {
				--depth;
				if (E[i] != ')') ERROR("���� ')'�� �ִ� �ڸ��� �ٸ� ���ڰ� �ֽ��ϴ�.");
			}
			else {
				int a, b; if (fscanf(in, "%d%d", &a, &b) != 2) ERROR("??");
				if (E[i] == ')') {
					if (depth == 0) ERROR("�ùٸ��� ���� ��ȣ���� ����߽��ϴ�.");
					--depth;
					tcost += b;
				}
				else if (E[i] == '(') {
					++depth;
					tcost += a;
				}
				else {
					ERROR("������ ���ڿ��� '(', ')'�� ������ �ٸ� ���ڰ� �ֽ��ϴ�.");
				}
			}
			if (depth < 0) ERROR("�ùٸ��� ���� ��ȣ���� ����߽��ϴ�.");
		}

		if (depth != 0) ERROR("�ùٸ��� ���� ��ȣ���� ����߽��ϴ�.");
		if (cost != tcost) ERROR("������ ���ڿ��� ���� ���� ����� ����� �ٸ��ϴ�.");
	}

	printf("Correct");
	return 0;
}
