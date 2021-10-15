drop table if exists dictionary;
drop table if exists decldictionaryension;
drop table if exists flex;

create table flex
(
	id_flex int(7) not null auto_increment,
    -- флексий максимально 24 для прилагательных и местоимений (6 падежей ед.ч м.р., ж.р.,ср.р + мн.ч), --
    -- 12 для существительных (6 падежей ед.ч + мн.ч) --
    flex_1_1 varchar(5) default null,
    flex_1_2 varchar(5) default null,
    flex_1_3 varchar(5) default null,
    flex_1_4 varchar(5) default null,
    flex_1_5 varchar(5) default null,
    flex_1_6 varchar(5) default null,
    
    flex_2_1 varchar(5) default null,
    flex_2_2 varchar(5) default null,
    flex_2_3 varchar(5) default null,
    flex_2_4 varchar(5) default null,
    flex_2_5 varchar(5) default null,
    flex_2_6 varchar(5) default null,
    
	flex_3_1 varchar(5) default null,
    flex_3_2 varchar(5) default null,
    flex_3_3 varchar(5) default null,
    flex_3_4 varchar(5) default null,
    flex_3_5 varchar(5) default null,
    flex_3_6 varchar(5) default null,
    
	flex_4_1 varchar(5) default null,
    flex_4_2 varchar(5) default null,
    flex_4_3 varchar(5) default null,
    flex_4_4 varchar(5) default null,
    flex_4_5 varchar(5) default null,
    flex_4_6 varchar(5) default null,
    
    primary key(id_flex)
);

create table declension
(
	id_declension int(4) not null auto_increment,
    part_of_speech varchar(11),
    set_of_flexes int(7) not null,
    primary key(id_declension),
    foreign key(set_of_flexes) references flex(id_flex)
);

create table dictionary
(
	id_dictionary int(11) not null auto_increment,
    is_mutable boolean,
    part_of_speech varchar(11), 
    first_form varchar(45),
    quasibase varchar(45) not null,
    declension_type int(4) default null, 
    
    primary key(id_dictionary),
    check(
    (part_of_speech in ('существительное', 'прилагательное', 'местоимение') AND is_mutable and part_of_speech is not null) 
    OR
    (part_of_speech in ('наречие', 'предлог') AND (is_mutable is false) and part_of_speech is not null)),
    unique(first_form),
    foreign key(declension_type) references declension(id_declension)
	-- constraint declension_type_fk foreign key(), --
);