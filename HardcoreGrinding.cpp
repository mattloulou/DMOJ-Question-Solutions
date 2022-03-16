using namespace std;
#include <unordered_map>
#include <iostream>

int main() {
    unordered_map<int, int> start_times;
    unordered_map<int, int> end_times;

    int inputs;
    cin >> inputs;

    int start, end;
    int largest_end = 0;

    for (int i = 0; i < inputs; ++i) {
        
        //get the start and end values
        cin >> start >> end;
        
        // if (start_times.find(start) != start_times.end()) {
        //     start_times.at(start) += 1;
        // } else {
        //     start_times.insert({start,1});
        // }
        start_times[start] += 1;

        // if (end_times.find(end) != end_times.end()) {
        //     end_times.at(end) += 1;
        // } else {
        //     end_times.insert({end,1});
        // }
        end_times[end] += 1;

        largest_end = max(largest_end, end);

    }

    int max_concurrent = 0;
    int concurrent = 0;

    //now go from time=0 until time=largest_end (the last end-time).
    for (int i = 0; i <= largest_end; ++i) {
        
        if (start_times.find(i) != start_times.end()) {
            concurrent += start_times.at(i);
        }

        if (end_times.find(i) != end_times.end()) {
            concurrent -= end_times.at(i);
        }

        max_concurrent = max(concurrent, max_concurrent);
    }

    cout << max_concurrent;

    //debug printing:
    // cout << "printing maps: " << endl;
    // for (auto i : start_times) {
    //     cout << i.first << " " << i.second << endl;
    // }

}