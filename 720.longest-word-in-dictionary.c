/*
 * @lc app=leetcode id=720 lang=c
 *
 * [720] Longest Word in Dictionary
 */

typedef struct node {
    bool end;
    struct node *children[26];
} Node;

int cmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

char *longestWord(char **words, int wordsSize) {
    qsort(words, wordsSize, sizeof(words[0]), cmp);
    Node *trie = malloc(sizeof(Node));
    for (int i = 0; i < 26; i++) trie->children[i] = NULL;
    trie->end = true;
    int max = 0;
    int maxIndex = -1;
    for (int i = 0; i < wordsSize; i++) {
        Node *temp = trie;
        int tempMax = 0;
        int len = strlen(words[i]);
        bool jump = false;
        for (int j = 0; j < len; j++) {
            Node *n;
            if (temp->children[words[i][j] - 'a'] == NULL) {
                n = malloc(sizeof(Node));
                for (int i = 0; i < 26; i++) n->children[i] = NULL;
                n->end = false;
            } else {
                n = temp->children[words[i][j] - 'a'];
            }
            if (j == len - 1) n->end = true;
            temp = temp->children[words[i][j] - 'a'] = n;
            if (temp->end == false) jump = true;
            if (temp->end == true) tempMax++;
            if (j == len - 1 && !jump && (tempMax > max || (tempMax == max && maxIndex >= 0 && words[i][0] < words[maxIndex][0]))) {
                max = tempMax;
                maxIndex = i;
            }
        }
    }
    return words[maxIndex];
}
