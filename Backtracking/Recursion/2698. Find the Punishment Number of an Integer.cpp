class Solution {
public:
    bool isGood(int i, int sum, string sq, int num) {
        if(sum > num) {
            return false;
        }
        if(i == sq.size()) {
            return sum == num;
        }

        // 81 => 9
        for(int j=i; j<sq.size(); j++) { // partition
            string substr = sq.substr(i, j-i+1);
            int val = std::stoi(substr);
            if(isGood(j+1, sum + val, sq, num)) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;

        for(int num=1; num<=n; num++) {
            int sq = num * num;
            string temp = std::to_string(sq);
            if(isGood(0, 0, temp, num)) {
                sum += sq;
            }
        }

        return sum;
    }
};