# Write your MySQL query statement below
select e1.id from Weather e1 join Weather e2 on  e1.recordDate = DATE_ADD(e2.recordDate,INTERVAL 1 DAY) where e1.temperature>e2.temperature;