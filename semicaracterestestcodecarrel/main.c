// Semi-graphic characters sample code
// Xavier Carrel
// Feb 2019

#include <stdio.h>
#include <windows.h>

#define STLC 218 // ┌, Single Top Left Corner
#define STRC 191 // ┐, Single Top Right Corner
#define SBLC 192 // └, Single Bottom Left Corner
#define SBRC 217 // ┘, Single Bottom Right Corner
#define SVSB 179 // │, Single Vertical Simple Border
#define SVRB 180 // ┤, Single Vertical Right Border
#define SVLB 195 // ├, Single Vertical Left Border
#define SHSB 196 // ─, Single Horizontal Simple Border
#define SHBB 193 // ┴, Single Horizontal Bottom Border
#define SHTB 194 // ┬, Single Horizontal Top Border
#define SC   197 // ┼, Single Center
#define DTLC 201 // ╔, Double Top Left Corner
#define DTRC 187 // ╗, Double Top Right Corner
#define DBLC 200 // ╚, Double Bottom Left Corner
#define DBRC 188 // ╝, Double Bottom Right Corner
#define DVSB 186 // ║, Double Vertical Simple Border
#define DVRB 185 // ╣, Double Vertical Right Border
#define DVLB 204 // ╠, Double Vertical Left Border
#define DHSB 205 // ═, Double Horizontal Simple Border
#define DHBB 202 // ╩, Double Horizontal Bottom Border
#define DHTB 203 // ╦, Double Horizontal Top Border
#define DC   206 // ╬, Double Center

int main(void)
{
    SetConsoleOutputCP(65001); // For accented characters
    printf ("Une grille basée sur les lignes simples:\n");
    SetConsoleOutputCP(437); // For semi-graphic characters
    printf ("%c%c%c%c%c%c%c%c%c\n",STLC,SHSB,SHSB,SHSB,SHTB,SHSB,SHSB,SHSB,STRC);
    printf ("%c   %c   %c\n",SVSB,SVSB,SVSB);
    printf ("%c%c%c%c%c%c%c%c%c\n",SVLB,SHSB,SHSB,SHSB,SC,SHSB,SHSB,SHSB,SVRB);
    printf ("%c   %c   %c\n",SVSB,SVSB,SVSB);
    printf ("%c%c%c%c%c%c%c%c%c\n",SBLC,SHSB,SHSB,SHSB,SHBB,SHSB,SHSB,SHSB,SBRC);

    SetConsoleOutputCP(65001); // For accented characters
    printf ("\n\nUne grille basée sur les lignes doubles:\n");
    SetConsoleOutputCP(437); // For semi-graphic characters
    printf ("%c%c%c%c%c%c%c%c%c\n",DTLC,DHSB,DHSB,DHSB,DHTB,DHSB,DHSB,DHSB,DTRC);
    printf ("%c b %c b %c\n",DVSB,DVSB,DVSB);
    printf ("%c%c%c%c%c%c%c%c%c\n",DVLB,DHSB,DHSB,DHSB,DC,DHSB,DHSB,DHSB,DVRB);
    printf ("%c a %c a %c\n",DVSB,DVSB,DVSB);
    printf ("%c%c%c%c%c%c%c%c%c\n",DBLC,DHSB,DHSB,DHSB,DHBB,DHSB,DHSB,DHSB,DBRC);
    getchar();
    getchar();
}