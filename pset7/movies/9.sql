SELECT DISTINCT name
    FROM stars
    JOIN movies ON movies.id = movie_id
    JOIN people ON people.id = person_id
    WHERE year = 2004
    ORDER BY birth ASC, name DESC