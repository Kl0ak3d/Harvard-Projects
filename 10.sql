-- List people with rating of 9 or more
ELECT name FROM people

WHERE id IN (
SELECT DISTINCT directors.person_id
FROM directors J
OIN movies ON movies.id = directors.movie_id
WHERE id
IN (SELECT movie_id
FROM ratings
WHERE rating >= "9.0"))
