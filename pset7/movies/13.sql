SELECT DISTINCT name
    FROM stars
    JOIN movies ON movies.id = stars.movie_id
    JOIN people ON people.id = stars.person_id
    WHERE name <> "Kevin Bacon"
    AND title IN (
        SELECT title FROM stars
        JOIN movies ON movies.id = stars.movie_id
        JOIN people ON people.id = stars.person_id
        WHERE name = "Kevin Bacon"
        AND birth = 1958
    )