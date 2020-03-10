SELECT DISTINCT name
    FROM directors
    JOIN ratings ON directors.movie_id = ratings.movie_id
    JOIN people ON people.id = person_id
    WHERE rating >= 9