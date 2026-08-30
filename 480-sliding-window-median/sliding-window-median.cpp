class Solution {
public:

    typedef pair<int, int> P;   // {value, index}

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        vector<double> ans;

        // Left side -> max heap
        priority_queue<P> pq;

        // Right side -> min heap
        priority_queue<P, vector<P>, greater<P>> pqm;

        // where[i] = 0 -> pq
        // where[i] = 1 -> pqm
        vector<int> where(n);

        // deleted[i] = true means element is out of window
        vector<bool> deleted(n, false);

        int x = 0;   // size of pq
        int y = 0;   // size of pqm

        for (int j = 0; j < n; j++) {

            P a = {nums[j], j};

            // --------------------------------
            // INSERT
            // --------------------------------

            if (pq.empty() || nums[j] <= pq.top().first) {

                pq.push(a);
                where[j] = 0;
                x++;
            }
            else {

                pqm.push(a);
                where[j] = 1;
                y++;
            }


            // --------------------------------
            // BALANCE
            // --------------------------------

            if (x > y + 1) {

                P temp = pq.top();
                pq.pop();

                pqm.push(temp);

                where[temp.second] = 1;

                x--;
                y++;
            }

            else if (y > x) {

                P temp = pqm.top();
                pqm.pop();

                pq.push(temp);

                where[temp.second] = 0;

                y--;
                x++;
            }


            // --------------------------------
            // REMOVE OLD ELEMENT
            // --------------------------------

            if (j >= k) {

                int old = j - k;

                deleted[old] = true;

                // EXACTLY know which heap
                // contained this element

                if (where[old] == 0)
                    x--;
                else
                    y--;


                // Remove deleted elements
                // from top of pq

                while (!pq.empty() &&
                       deleted[pq.top().second]) {

                    pq.pop();
                }


                // Remove deleted elements
                // from top of pqm

                while (!pqm.empty() &&
                       deleted[pqm.top().second]) {

                    pqm.pop();
                }


                // --------------------------------
                // BALANCE AFTER REMOVAL
                // --------------------------------

                if (x > y + 1) {

                    P temp = pq.top();
                    pq.pop();

                    pqm.push(temp);

                    where[temp.second] = 1;

                    x--;
                    y++;
                }

                else if (y > x) {

                    P temp = pqm.top();
                    pqm.pop();

                    pq.push(temp);

                    where[temp.second] = 0;

                    y--;
                    x++;
                }
            }


            // --------------------------------
            // MEDIAN
            // --------------------------------

            if (j >= k - 1) {

                // Clean tops
                while (!pq.empty() &&
                       deleted[pq.top().second]) {

                    pq.pop();
                }

                while (!pqm.empty() &&
                       deleted[pqm.top().second]) {

                    pqm.pop();
                }


                if (k % 2 == 1) {

                    ans.push_back(pq.top().first);
                }
                else {

                    double m =
                        ((double)pq.top().first +
                         (double)pqm.top().first) / 2.0;

                    ans.push_back(m);
                }
            }
        }

        return ans;
    }
};