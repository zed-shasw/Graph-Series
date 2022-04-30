struct node
{
    int x, y, time;
    node(int x, int y, int time)
    {
        this->x = x;
        this->y = y;
        this->time = time;
    }
};

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int cntOranges = 0;

        queue<node> q;

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == 2)
                    q.push(node(i, j, 0));
                if (grid[i][j] != 0)
                    cntOranges++;
            }
        }

        int cnt = 0;
        int ans = 0;

        while (q.size())
        {
            int x = q.front().x;
            int y = q.front().y;
            int time = q.front().time;
            q.pop();

            cnt++;
            ans = max(ans, time);
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, -1, 0, 1};

            for (int i = 0; i < 4; ++i)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < row && newY >= 0 && newY < col && grid[newX][newY] == 1)
                {
                    grid[newX][newY] = 2;
                    q.push(node(newX, newY, time + 1));
                }
            }
        }

        if (cntOranges == cnt)
            return ans;
        return -1;
    }
};