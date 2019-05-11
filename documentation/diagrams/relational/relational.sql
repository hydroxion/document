-- -----------------------------------------------------
-- Schema proto_buffer
-- -----------------------------------------------------
DROP SCHEMA IF EXISTS `proto_buffer` ;

CREATE SCHEMA IF NOT EXISTS `proto_buffer` DEFAULT CHARACTER SET utf8 ;

USE `proto_buffer` ;


-- -----------------------------------------------------
-- Table `proto_buffer`.`user`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `proto_buffer`.`user` ;

CREATE TABLE IF NOT EXISTS `proto_buffer`.`user` (
  `id` CHAR(40) NOT NULL,
  `first_name` VARCHAR(45) NULL,
  `second_name` VARCHAR(45) NULL,
  `email` VARCHAR(65) NOT NULL,
  `password` VARCHAR(20) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  UNIQUE INDEX `email_UNIQUE` (`email` ASC))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `proto_buffer`.`document`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `proto_buffer`.`document` ;

CREATE TABLE IF NOT EXISTS `proto_buffer`.`document` (
  `id` CHAR(40) NOT NULL,
  `title` VARCHAR(250) NOT NULL,
  `type` VARCHAR(50) NOT NULL,
  `idiom` CHAR(2) NULL,
  `created_at` DATETIME NOT NULL,
  `user_id` CHAR(40) NOT NULL,
  PRIMARY KEY (`id`, `user_id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `fk_document_user_idx` (`user_id` ASC),
  CONSTRAINT `fk_document_user`
    FOREIGN KEY (`user_id`)
    REFERENCES `proto_buffer`.`user` (`id`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `proto_buffer`.`category`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `proto_buffer`.`category` ;

CREATE TABLE IF NOT EXISTS `proto_buffer`.`category` (
  `id` CHAR(40) NOT NULL,
  `category` VARCHAR(50) NOT NULL,
  `document_id` CHAR(40) NOT NULL,
  `document_user_id` CHAR(40) NOT NULL,
  PRIMARY KEY (`id`, `document_id`, `document_user_id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  UNIQUE INDEX `category_UNIQUE` (`category` ASC),
  INDEX `fk_category_document1_idx` (`document_id` ASC, `document_user_id` ASC),
  CONSTRAINT `fk_category_document1`
    FOREIGN KEY (`document_id` , `document_user_id`)
    REFERENCES `proto_buffer`.`document` (`id` , `user_id`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `proto_buffer`.`comment`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `proto_buffer`.`comment` ;

CREATE TABLE IF NOT EXISTS `proto_buffer`.`comment` (
  `id` CHAR(40) NOT NULL,
  `comment` LONGTEXT NOT NULL,
  `document_id` CHAR(40) NOT NULL,
  `document_user_id` CHAR(40) NOT NULL,
  PRIMARY KEY (`id`, `document_id`, `document_user_id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `fk_comment_document1_idx` (`document_id` ASC, `document_user_id` ASC),
  CONSTRAINT `fk_comment_document1`
    FOREIGN KEY (`document_id` , `document_user_id`)
    REFERENCES `proto_buffer`.`document` (`id` , `user_id`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `proto_buffer`.`file_meta`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `proto_buffer`.`file_meta` ;

CREATE TABLE IF NOT EXISTS `proto_buffer`.`file_meta` (
  `id` CHAR(40) NOT NULL,
  `mime_type` VARCHAR(40) NOT NULL,
  `name` VARCHAR(45) NOT NULL,
  `size` BIGINT NOT NULL,
  `document_id` CHAR(40) NOT NULL,
  `document_user_id` CHAR(40) NOT NULL,
  PRIMARY KEY (`id`, `document_id`, `document_user_id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `fk_file_meta_document1_idx` (`document_id` ASC, `document_user_id` ASC),
  CONSTRAINT `fk_file_meta_document1`
    FOREIGN KEY (`document_id` , `document_user_id`)
    REFERENCES `proto_buffer`.`document` (`id` , `user_id`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `proto_buffer`.`file`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `proto_buffer`.`file` ;

CREATE TABLE IF NOT EXISTS `proto_buffer`.`file` (
  `id` CHAR(40) NOT NULL,
  `file` LONGBLOB NOT NULL,
  `file_meta_id` CHAR(40) NOT NULL,
  `file_meta_document_id` CHAR(40) NOT NULL,
  `file_meta_document_user_id` CHAR(40) NOT NULL,
  PRIMARY KEY (`id`, `file_meta_id`, `file_meta_document_id`, `file_meta_document_user_id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `fk_file_file_meta1_idx` (`file_meta_id` ASC, `file_meta_document_id` ASC, `file_meta_document_user_id` ASC),
  CONSTRAINT `fk_file_file_meta1`
    FOREIGN KEY (`file_meta_id` , `file_meta_document_id` , `file_meta_document_user_id`)
    REFERENCES `proto_buffer`.`file_meta` (`id` , `document_id` , `document_user_id`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION)
ENGINE = InnoDB;

-- -----------------------------------------------------
-- Table `proto_buffer`.`keywords`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `proto_buffer`.`keywords` ;

CREATE TABLE IF NOT EXISTS `proto_buffer`.`keywords` (
  `id` CHAR(40) NOT NULL,
  `keywords` TEXT NOT NULL,
  `document_id` CHAR(40) NOT NULL,
  `document_user_id` CHAR(40) NOT NULL,
  PRIMARY KEY (`id`, `document_id`, `document_user_id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `fk_keywords_document1_idx` (`document_id` ASC, `document_user_id` ASC),
  CONSTRAINT `fk_keywords_document1`
    FOREIGN KEY (`document_id` , `document_user_id`)
    REFERENCES `proto_buffer`.`document` (`id` , `user_id`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `proto_buffer`.`metric`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `proto_buffer`.`metric` ;

CREATE TABLE IF NOT EXISTS `proto_buffer`.`metric` (
  `id` CHAR(40) NOT NULL,
  `likes` BIGINT NOT NULL,
  `views` BIGINT NOT NULL,
  `dislikes` BIGINT NOT NULL,
  `document_id` CHAR(40) NOT NULL,
  `document_user_id` CHAR(40) NOT NULL,
  PRIMARY KEY (`id`, `document_id`, `document_user_id`),
  UNIQUE INDEX `id_UNIQUE` (`id` ASC),
  INDEX `fk_metric_document1_idx` (`document_id` ASC, `document_user_id` ASC),
  CONSTRAINT `fk_metric_document1`
    FOREIGN KEY (`document_id` , `document_user_id`)
    REFERENCES `proto_buffer`.`document` (`id` , `user_id`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION)
ENGINE = InnoDB;