#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void changesquare(int quadrant, char direction, char board[8][8]);
int isbwon(char board[8][8]);
int iswwon(char board[8][8]);

#ifdef __cplusplus
}
#endif
