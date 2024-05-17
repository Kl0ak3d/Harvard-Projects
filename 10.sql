-- List people with rating of 9 or more
SELECT DISTINCT name FROM people, directors, ratings
WHERE directors.person_id = people.id
AND directors.movie_id = ratings.movie_id
AND rating >= 9.0;

