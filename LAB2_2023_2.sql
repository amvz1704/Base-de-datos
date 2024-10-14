--PREGUNTA 1
SELECT C.DESCRIPCION AS "CATEGORIA" , 'INACTIVO' AS "ESTADO", COUNT(*) FROM BS_CATEGORIA C, BS_PRENDA P WHERE
C.IDCATEGORIA = P.IDCATEGORIA AND C.ESTADO = 'I'
GROUP BY C.DESCRIPCION, C.ESTADO
ORDER BY 3 DESC, 1 ASC;

--PREGUNTA 2

DROP VIEW PREG1;
CREATE VIEW PREG1 AS SELECT C.DESCRIPCION AS "CATEGORIA" , 'INACTIVO' AS "ESTADO",
COUNT(*) AS "CANTIDAD" FROM BS_CATEGORIA C, BS_PRENDA P WHERE
C.IDCATEGORIA = P.IDCATEGORIA AND C.ESTADO = 'I' AND ROWNUM = 1
GROUP BY C.DESCRIPCION, C.ESTADO
ORDER BY 3 DESC, 1 ASC;


SELECT C.DESCRIPCION AS "CATEGORIA", P.DESCRIPCION AS "PRENDA", P.COLOR 
FROM BS_CATEGORIA C, BS_PRENDA P WHERE(
P.IDCATEGORIA = C.IDCATEGORIA AND 
C.DESCRIPCION IN (SELECT CATEGORIA FROM PREG1));

--PREGUNTA 3
SELECT C.DESCRIPCION, P.IDPRENDA, P.DESCRIPCION, P.COLOR FROM BS_PRENDA P, BS_CATEGORIA C 
WHERE P.IDCATEGORIA = C.IDCATEGORIA AND P.IDCATEGORIA IN (SELECT IDCATEGORIA FROM
(SELECT P.IDCATEGORIA, COUNT(*) FROM BS_PRENDA P, BS_CATEGORIA C
WHERE P.IDCATEGORIA = C.IDCATEGORIA
GROUP BY P.IDCATEGORIA
HAVING COUNT(*) > 10))
ORDER BY 2;

--PREGUNTA 4

SELECT TALLA, COUNT(*) FROM BS_MATRIZ_TALLA
GROUP BY TALLA
ORDER BY 1 ASC,2 DESC;

--PREGUNTA 5
SELECT C.DESCRIPCION FROM BS_CATEGORIA C WHERE C.IDCATEGORIA IN(SELECT IDCATEGORIA FROM
(SELECT P.IDCATEGORIA, T.TALLA, T.IDPRENDA FROM BS_MATRIZ_TALLA T, BS_PRENDA P
WHERE (T.TALLA != 'XS' AND T.TALLA != 'S' AND T.TALLA != 'XXL' AND T.TALLA != 'XXXL') 
 AND P.IDPRENDA = T.IDPRENDA AND T.PRECIO_VENTA > 50));
 
--PREGUNTA 6
SELECT C.DESCRIPCION, AVG(T.PRECIO_VENTA) 
FROM BS_CATEGORIA C, BS_PRENDA P, BS_MATRIZ_TALLA T
WHERE(
    C.IDCATEGORIA = P.IDCATEGORIA AND P.IDPRENDA = T.IDPRENDA)
GROUP BY C.DESCRIPCION, P.DESCRIPCION
ORDER BY 2 DESC;

--PREGUNTA 8
SELECT C.DESCRIPCION, P.DESCRIPCION, P.COLOR, T.TALLA, T.PRECIO_VENTA 
FROM BS_CATEGORIA C, BS_PRENDA P, BS_MATRIZ_TALLA T
WHERE(
    C.IDCATEGORIA = P.IDCATEGORIA AND P.IDPRENDA = T.IDPRENDA 
    AND T.PRECIO_VENTA < (SELECT AVG(PRECIO_VENTA) FROM BS_MATRIZ_TALLA)
    )
    ORDER BY 4, 2 DESC;