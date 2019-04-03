
void printzigzag(string &input, int K) {
    int len = input.length();
    vector<string> output(K, string(len, ' '));

    int k = K-1;
    int inc = 1;

    for (int i = 0; i < len; i++) {
        if (k == 0)
            inc = 1;
        output[k][i] = input[i]==' '?'~':input[i];
        if (k + inc == K)
            inc = -1;
        k += inc;
    }

    for (int i = 0; i < K; i++)
        cout << output[i] << endl;
}

void printStringSinusoidally(string s) {
    printzigzag(s, 3);
}

