#INCLUDE<STDIO.H>
#INCLUDE<QUEUE>
#INCLUDE<STRING>
#INCLUDE<IOSTREAM>
USING NAMESPACE STD; 


INT MAIN() {
	DEQUE<STRING>D;
	INT N; SCANF("%D\N", &N);

	FOR(INT I=1; I<=N; I++){
		CHAR S[100];
		GETS_S(S);
		CHAR* TOK1 = STRTOK(S, " ");
		WHILE (TOK1 != NULL) {
			D.PUSH_BACK(TOK1);
			TOK1 = STRTOK(NULL, " ");
		}
		PRINTF("CASE #%D: ", I);
		WHILE (!D.EMPTY()) {
			COUT << D.BACK();
			PRINTF(" ");
			D.POP_BACK();
		}
		PRINTF("\N");
	}
}