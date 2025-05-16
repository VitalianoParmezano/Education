plugins {
    // Плагін для консольного Java-додатку
    application
}

repositories {
    // Використовуємо Maven Central для завантаження залежностей
    mavenCentral()
}

dependencies {
    // Основна бібліотека програми (можеш змінити або видалити, якщо не треба)
    implementation("com.google.guava:guava:32.1.2-jre")

    // Додаємо підтримку JUnit 5 для тестування
    testImplementation("org.junit.jupiter:junit-jupiter:5.10.0")
    testRuntimeOnly("org.junit.platform:junit-platform-launcher:1.10.0")
}

java {
    // Вказуємо потрібну версію Java
    toolchain {
        languageVersion.set(JavaLanguageVersion.of(21))
    }
}

application {
    // Вказуємо повне ім'я класу з методом main()
    mainClass.set("org.example.App")
}

// Активуємо підтримку JUnit 5
tasks.test {
    useJUnitPlatform()
}
