
class RatMaze {

    static int n = 4;

    static boolean isSafe(int maze[][], int x, int y, boolean visited[][]) {
        return x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y];
    }

    static void solve(int maze[][], int x, int y, boolean visited[][], String path) {

        if (x == n - 1 && y == n - 1) {
            System.out.println(path);
            return;
        }
        visited[x][y] = true;
        //down
        if (isSafe(maze, x + 1, y, visited)) {
            solve(maze, x + 1, y, visited, path + "D");

        }
        //right
        if (isSafe(maze, x, y + 1, visited)) {
            solve(maze, x, y + 1, visited, path + "R");

        }
        //left
        if (isSafe(maze, x, y - 1, visited)) {
            solve(maze, x, y - 1, visited, path + "L");

        }
        if (isSafe(maze, x - 1, y, visited)) {
            solve(maze, x - 1, y, visited, path + "U");

        }
    }

    public static void main(String[] args) {
        int[][] maze = {
            {1, 0, 0, 0},
            {1, 1, 0, 1},
            {1, 1, 0, 0},
            {1, 1, 1, 1}
        };
        boolean visited[][] = new boolean[n][n];
        if (maze[0][0] == 1) {
            solve(maze, 0, 0, visited, "");
        }
    }
}
