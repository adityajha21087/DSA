class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
       
        int x1 = rec1[0];
        int x2 = rec1[2];
        int y1 = rec1[1];
        int y2 = rec1[3];

        int a1 = rec2[0];
        int b1 = rec2[1];
        int a2 = rec2[2];
        int b2 = rec2[3];

        // x-overlap
        bool xOverlap = (a1 < x2 && x1 < a2);

        // y-overlap
        bool yOverlap = (b1 < y2 && y1 < b2);

        return xOverlap && yOverlap;
    }
};