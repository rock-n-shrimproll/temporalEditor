drop table if exists dictionary;
drop table if exists declension;
drop table if exists flex;

create table flex
(
    id_flex INTEGER PRIMARY KEY AUTOINCREMENT,

    flex_1_1 TEXT default null,
    flex_1_2 TEXT default null,
    flex_1_3 TEXT default null,
    flex_1_4 TEXT default null,
    flex_1_5 TEXT default null,
    flex_1_6 TEXT default null,

    flex_2_1 TEXT default null,
    flex_2_2 TEXT default null,
    flex_2_3 TEXT default null,
    flex_2_4 TEXT default null,
    flex_2_5 TEXT default null,
    flex_2_6 TEXT default null,

    flex_3_1 TEXT default null,
    flex_3_2 TEXT default null,
    flex_3_3 TEXT default null,
    flex_3_4 TEXT default null,
    flex_3_5 TEXT default null,
    flex_3_6 TEXT default null,

    flex_4_1 TEXT default null,
    flex_4_2 TEXT default null,
    flex_4_3 TEXT default null,
    flex_4_4 TEXT default null,
    flex_4_5 TEXT default null,
    flex_4_6 TEXT default null,
    
    UNIQUE(flex_1_1,flex_1_2,flex_1_3,flex_1_4,flex_1_5,flex_1_6,flex_2_1,flex_2_2,flex_2_3,flex_2_4,flex_2_5,flex_2_6,flex_3_1,flex_3_2,flex_3_3,flex_3_4,flex_3_5,flex_3_6,flex_4_1,flex_4_2,flex_4_3,flex_4_4,flex_4_5,flex_4_6)
--     unique(flex_1_1, flex_1_2, flex_1_3, flex_1_4, flex_1_5, flex_1_6),
--     unique(flex_2_1, flex_2_2, flex_2_3, flex_2_4, flex_2_5, flex_2_6),
--     unique(flex_3_1, flex_3_2, flex_3_3, flex_3_4, flex_3_5, flex_3_6),
--     unique(flex_4_1, flex_4_2, flex_4_3, flex_4_4, flex_4_5, flex_4_6)
);

create table declension
(
    id_declension INTEGER PRIMARY KEY AUTOINCREMENT,

    part_of_speech TEXT,
    set_of_flexes INTEGER not null,

    foreign key(set_of_flexes) references flex(id_flex)
);

create table dictionary
(
    id_dictionary INTEGER PRIMARY KEY AUTOINCREMENT,

    is_mutable boolean,
    part_of_speech TEXT,
    first_form TEXT,
    quasibase TEXT not null,
    declension_type INTEGER default null,

    check(
        (part_of_speech in ('существительное', 'прилагательное', 'местоимение') AND is_mutable and part_of_speech is not null)
        OR
        (part_of_speech in ('наречие', 'предлог') AND (is_mutable is false) and part_of_speech is not null)),
    
    unique(first_form),

    foreign key(declension_type) references declension(id_declension)
);