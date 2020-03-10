SELECT name
    FROM stars
    JOIN movies ON movies.id = movie_id
    JOIN people ON people.id = person_id
    WHERE title = "Toy Story"