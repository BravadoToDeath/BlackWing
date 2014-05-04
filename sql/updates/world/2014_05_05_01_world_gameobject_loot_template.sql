/*
SQLyog Community v11.31 (32 bit)
MySQL - 5.6.15 
*********************************************************************
*/
/*!40101 SET NAMES utf8 */;

/*Delete previous GO loot for new loot. Group ID's are non blizzlike */
DELETE FROM `gameobject_loot_template` WHERE `entry`=208045;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(208045, 60231, 46, 1, 1, 1, 1),
(208045, 60237, 42, 1, 2, 1, 1),
(208045, 60232, 42, 1, 1, 1, 1),
(208045, 60228, 42, 1, 2, 1, 1),
(208045, 60227, 42, 1, 1, 1, 1),
(208045, 60230, 35, 1, 2, 1, 1),
(208045, 60234, 35, 1, 1, 1, 1),
(208045, 60226, 31, 1, 2, 1, 1),
(208045, 60233, 31, 1, 1, 1, 1),
(208045, 60229, 27, 1, 2, 1, 1),
(208045, 60238, 23, 1, 1, 1, 1),
(208045, 60236, 23, 1, 2, 1, 1),
(208045, 60235, 18, 1, 1, 1, 1);