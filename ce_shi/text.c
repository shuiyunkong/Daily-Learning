#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORD_COUNT 222
#define MAX_LEN 50

// 第一单元所有单词（按原顺序，去重后共222个）
const char* words[WORD_COUNT] = {
    "space", "universe", "unite", "reunite", "union", "diverse", "convert", "reverse", "anniversary",
    "annual", "controversy", "contrary", "contrast", "nasty", "astronaut", "heaven", "satellite",
    "moon", "develop", "evolve", "revolve", "involve", "advance", "ahead", "ongoing", "improve",
    "approve", "proof", "enhance", "enable", "enlarge", "enrich", "fasten", "tight", "buckle",
    "watertight", "loose", "undo", "form", "formal", "uniform", "formation", "reform", "format",
    "conform", "comply", "formulate", "formula", "program", "perform", "drill", "inform", "notify",
    "noticeable", "coast", "toast", "roast", "sail", "shore", "island", "inland", "beach", "bench",
    "harbor", "embrace", "bay", "shelter", "shade", "shave", "belt", "bond", "bind", "blind",
    "deaf", "bend", "twist", "blend", "mix", "stir", "mountain", "fountain", "profound", "foundation",
    "base", "basic", "basis", "mount", "amount", "soar", "ascend", "descend", "decline", "incline",
    "ancestor", "ancient", "consensus", "proceed", "procession", "troop", "process", "procedure",
    "access", "assess", "exceed", "beyond", "surplus", "extra", "excess", "success", "succeed",
    "successor", "excel", "stride", "wander", "crawl", "climb", "progress", "congress", "aggressive",
    "move", "motion", "mobile", "static", "motive", "motivate", "remove", "emotion", "rational",
    "ratio", "rate", "percentage", "promote", "action", "deed", "behave", "active", "react", "exact",
    "actual", "practical", "virtual", "fragment", "somewhat", "fraction", "portion", "proportion",
    "skeleton", "frame", "framework", "flame", "burn", "flash", "flesh", "fresh", "refresh",
    "flourish", "flour", "powder", "cure", "curious", "accurate", "secure", "rescue", "injure",
    "wound", "harm", "hazard", "danger", "stake", "risk", "gamble", "bet", "currency", "rental",
    "lease", "release", "recently", "modern", "era", "up-to-date", "outdated", "stale", "fashion",
    "temple", "temporary", "contemporary", "abundant", "ample", "mass", "massive", "massage",
    "numerous", "multiply", "gang", "band", "bandage", "sort", "resort", "flock", "crowd", "dozen",
    "population", "popularity", "prevail", "crew", "screw", "colleague", "personnel", "staff",
    "stuff", "infant", "adolescent", "idle", "youngster", "elder", "immigrate", "emigrate", "migrate",
    "surname", "namely", "remote"
};

// Fisher-Yates 洗牌算法
void shuffle(const char** arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        const char* temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    // 用当前时间初始化随机种子
    srand((unsigned int)time(NULL));

    // 复制指针数组（避免修改原数组）
    const char* shuffled[WORD_COUNT];
    for (int i = 0; i < WORD_COUNT; i++) {
        shuffled[i] = words[i];
    }

    // 随机打乱
    shuffle(shuffled, WORD_COUNT);

    // 输出所有单词（每行一个）
    for (int i = 0; i < WORD_COUNT; i++) {
        printf("%s\n", shuffled[i]);
    }

    system("pause");

    return 0;
}