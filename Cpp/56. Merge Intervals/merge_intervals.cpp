// Source : https://leetcode.com/problems/merge-intervals/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: http://www.cnblogs.com/grandyang/p/4370601.html
// Idea: sort intervals by left boundaries and then start to merge

/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool compare(Interval &a, Interval &b)
    {
        return (a.start<b.start);
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), compare);
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (res.back().end >= intervals[i].start) {
                res.back().end = max(res.back().end, intervals[i].end);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
