drop table if exists noun;
drop table if exists adjective;
drop table if exists pronoun;
drop table if exists adverb;
drop table if exists preposition;

drop table if exists noun_flex;
drop table if exists flex;
drop table if exists temporality;


create table noun_flex 
(
	noun_flex_id INTEGER PRIMARY KEY AUTOINCREMENT,
	
    noun_flex_1 TEXT not null,
    noun_flex_2 TEXT not null,
    noun_flex_3 TEXT not null,
    noun_flex_4 TEXT not null,
    noun_flex_5 TEXT not null,
    noun_flex_6 TEXT not null,
    
    UNIQUE(noun_flex_1, noun_flex_2, noun_flex_3, noun_flex_4, noun_flex_5, noun_flex_6)
);

create table flex 
(
	flex_id INTEGER PRIMARY KEY AUTOINCREMENT,
	
    flex_masc_1 TEXT not null,
    flex_masc_2 TEXT not null,
    flex_masc_3 TEXT not null,
    flex_masc_4 TEXT not null,
    flex_masc_5 TEXT not null,
    flex_masc_6 TEXT not null,

    flex_neu_1 TEXT not null,
    flex_neu_2 TEXT not null,
    flex_neu_3 TEXT not null,
    flex_neu_4 TEXT not null,
    flex_neu_5 TEXT not null,
    flex_neu_6 TEXT not null,

    flex_fem_1 TEXT not null,
    flex_fem_2 TEXT not null,
    flex_fem_3 TEXT not null,
    flex_fem_4 TEXT not null,
    flex_fem_5 TEXT not null,
    flex_fem_6 TEXT not null,

    flex_plur_1 TEXT not null,
    flex_plur_2 TEXT not null,
    flex_plur_3 TEXT not null,
    flex_plur_4 TEXT not null,
    flex_plur_5 TEXT not null,
    flex_plur_6 TEXT not null,
    
    UNIQUE(flex_masc_1,flex_masc_2,flex_masc_3,flex_masc_4,flex_masc_5,flex_masc_6,
    flex_neu_1,flex_neu_2,flex_neu_3,flex_neu_4,flex_neu_5,flex_neu_6,
    flex_fem_1,flex_fem_2,flex_fem_3,flex_fem_4,flex_fem_5,flex_fem_6,
    flex_plur_1,flex_plur_2,flex_plur_3,flex_plur_4,flex_plur_5,flex_plur_6)
);

create table temporality 
(
	temporality_id INTEGER PRIMARY KEY AUTOINCREMENT,
	
    temp_class TEXT,
    temp_type TEXT default null,
    temp_subtype TEXT default null,
    
    unique(temp_class, temp_type, temp_subtype)
);

create table adverb
(
	adv_id INTEGER PRIMARY KEY AUTOINCREMENT,
    
    firstform TEXT,
    temporality INTEGER not null,
    
    unique(firstform),
    foreign key(temporality) references temporality(temporality_id)
);

create table preposition
(
	prep_id INTEGER PRIMARY KEY AUTOINCREMENT,
    
    firstform TEXT,
    temporality INTEGER not null,
    
    unique(firstform),
    foreign key(temporality) references temporality(temporality_id)
);

create table adjective
(
	adj_id INTEGER PRIMARY KEY AUTOINCREMENT,
    
    firstform TEXT,
    quasibase TEXT,
    set_of_flexes INTEGER not null,
    temporality INTEGER not null,
    
    unique(firstform),
    unique(quasibase),
    foreign key(set_of_flexes) references flex(flex_id),
    foreign key(temporality) references temporality(temporality_id)
);

create table pronoun
(
	pronoun_id INTEGER PRIMARY KEY AUTOINCREMENT,
    
    firstform TEXT,
    quasibase TEXT,
    set_of_flexes INTEGER not null,
    
    unique(firstform),
    unique(quasibase),
    foreign key(set_of_flexes) references flex(flex_id)
);

create table noun
(
	noun_id INTEGER PRIMARY KEY AUTOINCREMENT,
    
    firstform TEXT,
    quasibase TEXT,
    set_of_flexes INTEGER not null,
    
    unique(firstform),
    unique(quasibase),
    foreign key(set_of_flexes) references noun_flex(noun_flex_id)
);