# LeetCode Tracker

# Project Details
## Data Schema
This is the schema I used for the sqlite db:
```sql
CREATE TABLE problems (
    problem_id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    link TEXT NOT NULL,
    created_date DATETIME NOT NULL,
    total_attempts_count INTEGER DEFAULT 0,
    last_attempt_date DATETIME NOT NULL,
    last_attempt_difficulty INTEGER NOT NULL, -- 1=Easy, 2=Medium, 3=Hard
    next_review_date DATETIME NOT NULL
);
CREATE INDEX idx_problems_next_review ON problems(next_review_date);

CREATE TABLE attempts (
    attempt_id INTEGER PRIMARY KEY AUTOINCREMENT,
    problem_id INTEGER NOT NULL,
    date DATETIME NOT NULL,
    time_taken INTEGER NOT NULL, -- Seconds
    perceived_difficulty INTEGER NOT NULL,
    strategy TEXT,
    tips TEXT,
    code_file_path TEXT NOT NULL,
    FOREIGN KEY (problem_id) REFERENCES problems(problem_id) ON DELETE CASCADE
);
CREATE INDEX idx_attempts_problem_id ON attempts(problem_id);

CREATE TABLE topics (
    topic_id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL UNIQUE
);

CREATE TABLE problem_topics (
    problem_id INTEGER NOT NULL,
    topic_id INTEGER NOT NULL,
    PRIMARY KEY (problem_id, topic_id),
    FOREIGN KEY (problem_id) REFERENCES problems(problem_id) ON DELETE CASCADE,
    FOREIGN KEY (topic_id) REFERENCES topics(topic_id) ON DELETE CASCADE
);
```
This is the code storage file system: <br>
```
problems -> problem_id -> code_per_attempt
```