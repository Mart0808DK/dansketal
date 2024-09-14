#include <stdio.h>
#include <string.h>

char *ones[] = {"", "et", "to", "tre", "fire", "fem", "seks", "syv", "otte", "ni", "ti", "elleve", "tolv", "tretten", "fjorten", "femten", "seksten", "sytten", "atten", "nitten"};
char *tens[] = {"", "", "tyve", "tredive", "fyrre", "halvtreds", "tres", "halvfjerds", "firs", "halvfems"};

void outputOnes(int tal, char *res) {
    sprintf(res, "%s", ones[tal]);
}

void outputTens(int tal, char *res) {
    if (tal < 20) {
        sprintf(res, "%s", ones[tal]);
    } else {
        int ten = tal / 10;
        int one = tal % 10;
        if (one == 0) {
            sprintf(res, "%s", tens[ten]);
        } else {
            sprintf(res, "%sog%s", tens[ten], ones[one]);
        }
    }
}

void outputHundreds(int tal, char *res) {
    int hundred = tal / 100;
    int remainder = tal % 100;
    char temp[100] = "";

    if (hundred > 0) {
        if (hundred == 1) {
            sprintf(res, "et hundrede");
        } else {
            sprintf(res, "%s hundrede", ones[hundred]);
        }
        if (remainder > 0) {
            strcat(res, " ");
            outputTens(remainder, temp);
            strcat(res, temp);
        }
    } else {
        outputTens(remainder, res);
    }
}

void outputThousands(int tal, char *res) {
    int thousand = tal / 1000;
    int remainder = tal % 1000;
    char temp[100] = "";

    if (thousand > 0) {
        if (thousand == 1) {
            sprintf(res, "et tusind");
        } else {
            outputHundreds(thousand, temp);
            sprintf(res, "%s tusind", temp);
        }
        if (remainder > 0) {
            strcat(res, " ");
            outputHundreds(remainder, temp);
            strcat(res, temp);
        }
    } else {
        outputHundreds(remainder, res);
    }
}

void outputMillions(int tal, char *res) {
    int million = tal / 1000000;
    int remainder = tal % 1000000;
    char temp[100] = "";

    if (million > 0) {
        if (million == 1) {
            sprintf(res, "en million");
        } else {
            outputHundreds(million, temp);
            sprintf(res, "%s millioner", temp);
        }
        if (remainder > 0) {
            strcat(res, " ");
            outputThousands(remainder, temp);
            strcat(res, temp);
        }
    } else {
        outputThousands(remainder, res);
    }
}

void outputBillions(int tal, char *res) {
    int billion = tal / 1000000000;
    int remainder = tal % 1000000000;
    char temp[100] = "";

    if (billion > 0) {
        if (billion == 1) {
            sprintf(res, "en milliard");
        } else {
            outputHundreds(billion, temp);
            sprintf(res, "%s milliarder", temp);
        }
        if (remainder > 0) {
            strcat(res, " ");
            outputMillions(remainder, temp);
            strcat(res, temp);
        }
    } else {
        outputMillions(remainder, res);
    }
}

void outputTrillions(long long tal, char *res) {
    long long trillion = tal / 1000000000000;
    long long remainder = tal % 1000000000000;
    char temp[100] = "";

    if (trillion > 0) {
        if (trillion == 1) {
            sprintf(res, "en billion");
        } else {
            outputHundreds(trillion, temp);
            sprintf(res, "%s billioner", temp);
        }
        if (remainder > 0) {
            strcat(res, " ");
            outputBillions(remainder, temp);
            strcat(res, temp);
        }
    } else {
        outputBillions(remainder, res);
    }
}

void dansketal(long long tal, char *res) {
    if (tal == 0) {
        sprintf(res, "nul");
    } else if (tal < 10) {
        outputOnes(tal, res);
    } else if (tal < 100) {
        outputTens(tal, res);
    } else if (tal < 1000) {
        outputHundreds(tal, res);
    } else if (tal < 1000000) {
        outputThousands(tal, res);
    } else if (tal < 1000000000) {
        outputMillions(tal, res);
    } else if (tal < 1000000000000) {
        outputBillions(tal, res);
    } else if (tal < 1000000000000000) {
        outputTrillions(tal, res);
    } else {
        sprintf(res, "tal for stort");
    }
}