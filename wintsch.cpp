#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    int start;
    int finish;
    int value;
};

// Function to compare jobs based on finish time
bool compareJobs(Job& job1, Job& job2) {
    return job1.finish < job2.finish;
}

// Function to find the latest non-overlapping job
int latestNonOverlap(vector<Job>& jobs, int index) {
    for (int i = index - 1; i >= 0; i--) {
        if (jobs[i].finish <= jobs[index].start) {
            return i;
        }
    }
    return -1;
}

// Function to find the maximum sum of values of jobs that can be selected
int weightedIntervalScheduling(vector<Job>& jobs) {
    // Sort jobs based on finish times
    sort(jobs.begin(), jobs.end(), compareJobs);

    int n = jobs.size();
    // Initialize DP table to store maximum values
    vector<int> dp(n);
    dp[0] = jobs[0].value;

    // Trace back to find the selected jobs
    vector<int> selectedJobs(n, -1);
    selectedJobs[0] = 0;

    for (int i = 1; i < n; i++) {
        // Include the current job
        int inclValue = jobs[i].value;
        int latest = latestNonOverlap(jobs, i);
        if (latest != -1) {
            inclValue += dp[latest];
        }
        // Store maximum value at this index
        dp[i] = max(inclValue, dp[i - 1]);
        // Update selectedJobs list
        if (inclValue > dp[i - 1]) {
            selectedJobs[i] = i;
        } else {
            selectedJobs[i] = selectedJobs[i - 1];
        }
    }

    // Trace back to find selected jobs
    int maxVal = dp[n - 1];
    int selectedAmount = 0;
    vector<Job> selectedList;
    for (int i = n - 1; i >= 0; i--) {
        if (dp[i] != dp[i - 1]) {
            selectedList.push_back(jobs[i]);
            selectedAmount++;
        }
    }

    // Output the result
    cout << "Maximum sum of selected job values: " << maxVal << endl;
    cout << "Number of selected jobs: " << selectedAmount << endl;
    cout << "Selected jobs:" << endl;
    for (int i = selectedList.size() - 1; i >= 0; i--) {
        cout << "Job: " << i + 1 << " Start: " << selectedList[i].start << " Finish: " << selectedList[i].finish << " Value: " << selectedList[i].value << endl;
    }

    return maxVal;
}

int main() {
    vector<Job> jobs = {
        {1, 3, 5},
        {2, 5, 6},
        {4, 6, 5},
        {6, 7, 4}
    };

    cout << weightedIntervalScheduling(jobs);

    return 0;
}
