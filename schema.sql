CREATE TABLE IF NOT EXISTS users (
    id INTEGER,
    username TEXT NOT NULL,
    hash TEXT NOT NULL,
    cash NUMERIC NOT NULL DEFAULT 10000.00,
    PRIMARY KEY(id)
);
CREATE UNIQUE INDEX IF NOT EXISTS username ON users (username);

CREATE TABLE IF NOT EXISTS transactions (
    id INTEGER,
    user_id INTEGER,
    transacted DEFAULT CURRENT_TIMESTAMP NOT NULL,
    company TEXT NOT NULL,
    symbol TEXT NOT NULL,
    shares NUMERIC NOT NULL,
    price NUMERIC NOT NULL,
    PRIMARY KEY(id),
    FOREIGN KEY(user_id) REFERENCES users(id)
);
CREATE TABLE history (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id INTEGER NOT NULL,
    name TEXT NOT NULL,
    symbol TEXT NOT NULL,
    shares INTEGER NOT NULL,
    action TEXT NOT NULL,
    balance TEXT NOT NULL,
    date TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES users (id)
);
