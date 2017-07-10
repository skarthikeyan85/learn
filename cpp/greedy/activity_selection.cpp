#include <bits/stdc++.h>

using namespace std;

/*
 * Greedy algo for activity selection problem
 * 1. sort the jobs based on finish times
 * 2. pick the first job
 * 3. for every other job - pick the job that starts after the previous job finished
 * */

struct activity {
    int start;
    int finish;
};

bool cmp_activity(activity one, activity two)
{
    return (one.finish < two.finish);
}

void print_all_activities(activity act[], int n)
{
    int i = 0, j = 1;

    sort(act, act + n, cmp_activity);

    cout << act[i].start << "," << act[i].finish << endl;

    for (j = 1; j < n; j++) {
        if (act[j].start >= act[i].finish) {
            i = j;
            cout << act[i].start << "," << act[i].finish << endl;
        }
    }

    return;
}

int main()
{
    activity act[6] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},
                       {5, 7}, {8, 9}};

    print_all_activities(act, 6);
    return 0;
}
